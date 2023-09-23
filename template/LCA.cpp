#include <bits/stdc++.h>
using namespace std;
/**
 * 树上倍增 + LCA
 * 倍增中， dp[x][i]表示节点 x 的第 2^i 个祖先， dp[x][0] 即为父节点
 * dp[x][i + 1] = dp[dp[x][i]][i]
 *
 * LCA中，首先预处理出深度，方便把x和y调整到同一深度，再一起跳
 * 往上跳的过程中，按照倍增的思想，先跳大的再跳小的，先跳 2^i , i = log_2(n)
 * 1.如果跳上去发现不存在，说明步子迈大了，这次不跳，将i-1继续尝试
 * 2.如果跳上去，发现x！=y，说明还要继续跳，这次尝试有效，将xy更新成他们的2^i祖先，i - 1继续跳
 * 3.如果某一次dp[x][i] == dp[y][i]，那么祖先可能在下面，跳了就没法反悔了，只能不跳，将i - 1继续尝试
 * 4.可以证明，当循环结束时，lca距离x和y就是父子距离，即lca = dp[x][0]
 */
class TreeAncestor
{
    vector<int> depth;
    vector<vector<int>> pa;

public:
    TreeAncestor(vector<pair<int, int>> &edges)
    {
        int n = edges.size() + 1;
        int m = 32 - __builtin_clz(n); // n 的二进制长度
        vector<vector<int>> g(n);
        for (auto [x, y] : edges)
        { // 节点编号从 0 开始
            g[x].push_back(y);
            g[y].push_back(x);
        }

        depth.resize(n);
        pa.resize(n, vector<int>(m, -1));
        function<void(int, int)> dfs = [&](int x, int fa)
        {
            pa[x][0] = fa;
            for (int y : g[x])
            {
                if (y != fa)
                {
                    depth[y] = depth[x] + 1;
                    dfs(y, x);
                }
            }
        };
        dfs(0, -1);

        // 先循环i，再循环节点x
        for (int i = 0; i < m - 1; i++)
            for (int x = 0; x < n; x++)
                if (int p = pa[x][i]; p != -1)
                    pa[x][i + 1] = pa[p][i];
    }

    int get_kth_ancestor(int node, int k)
    {
        for (; k; k &= k - 1)
            node = pa[node][__builtin_ctz(k)];
        return node;
    }

    // 返回 x 和 y 的最近公共祖先（节点编号从 0 开始）
    int get_lca(int x, int y)
    {
        if (depth[x] > depth[y])
            swap(x, y);
        // 使 y 和 x 在同一深度
        y = get_kth_ancestor(y, depth[y] - depth[x]);
        if (y == x)
            return x;
        for (int i = pa[x].size() - 1; i >= 0; i--)
        {
            int px = pa[x][i], py = pa[y][i];
            if (px != py)
            {
                x = px;
                y = py;
            }
        }
        return pa[x][0];
    }
};

int main()
{
}