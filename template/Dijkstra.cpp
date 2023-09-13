/**适用于单源最短路径
 * 设dis[x]表示从起点到x的最短路
 * 对于所有的y->x，如果dis[y]已经算出，那么dis[x]也很容易算出
 * 边如果比点数多平方倍，那么一般用邻接矩阵存图
 *
 */
#include <bits/stdc++.h>
using namespace std;
vector<int> dijkstra(vector<vector<pair<int, int>>> &g, int start)
{
    vector<int> dist(g.size(), INT_MAX);
    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.emplace(0, start);
    while (!pq.empty())
    {
        auto [d, x] = pq.top();
        pq.pop();
        if (d > dist[x])
            continue;
        for (auto [y, wt] : g[x])
        {
            int new_d = dist[x] + wt;
            if (new_d < dist[y])
            {
                dist[y] = new_d;
                pq.emplace(new_d, y);
            }
        }
    }
    return dist;
}

// 建好图输入，接收
// vector<vector<pair<int, int>>> g(n);
// for (auto &e : edges)
// {
//     int u = e[0], v = e[1], w = e[2];
//     g[u].emplace_back(v, w);
//     g[v].emplace_back(u, w);
// }
// auto dist = dijkstra(g, 0); // 从 0 出发的最短路