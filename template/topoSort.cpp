#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// ------------------------拓扑排序------------------------------------
vector<int> topo_sort(int n, vector<vector<int>> &prequire)
{
    vector<vector<int>> g(n);
    vector<int> indeg(n);
    for (auto &info : prequire)
    {
        int x = info[1], y = info[0]; // 这里要根据题目注意谁指向谁
        g[x].emplace_back(y);
        indeg[y]++;
    }
    vector<int> order;
    deque<int> q;
    for (int i = 0; i < n; i++)
        if (indeg[i] == 0)
            q.push_back(i);

    while (!q.empty())
    {
        int x = q.front();
        q.pop_front();
        order.emplace_back(x);
        for (auto &y : g[x])
        {
            indeg[y]--;
            if (indeg[y] == 0)
                q.push_back(y);
        }
    }
    if (n != order.size())
        return {};
    return order;
}

// ----------------------------------------------------------------------------------------
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    return 0;
}