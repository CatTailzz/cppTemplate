#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>> &edges)
    {
        // 建图
        vector<vector<int>> g(n);
        for (auto &e : edges)
        {
            int x = e[0], y = e[1];
            g[x].push_back(y);
            g[y].push_back(x);
        }
        vector<int> res(n);
        vector<int> size(n, 1); // 每棵子树的大小
        function<void(int, int, int)> dfs = [&](int x, int fa, int depth)
        {
            res[0] += depth;
            for (int y : g[x])
            {
                if (y != fa)
                {
                    dfs(y, x, depth + 1);
                    size[x] += size[y];
                }
            }
        };
        dfs(0, -1, 0);
        function<void(int, int)> reroot = [&](int x, int fa)
        {
            for (int y : g[x])
            {
                if (y != fa)
                {
                    res[y] = res[x] + n - 2 * size[y];
                    reroot(y, x);
                }
            }
        };
        reroot(0, -1);
        return res;
    }
};