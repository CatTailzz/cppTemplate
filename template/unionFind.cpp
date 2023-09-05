#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// -------------------------并查集------------------------------------
int n = 1005;
vector<int> father = vector<int>(n, 0);

// 并查集初始化
void init()
{
    for (int i = 0; i < n; ++i)
    {
        father[i] = i;
    }
}
// 并查集里寻根的过程
int find(int u)
{
    return u == father[u] ? u : father[u] = find(father[u]); // 路径压缩
}

// 判断 u 和 v是否找到同一个根
bool isSame(int u, int v)
{
    u = find(u);
    v = find(v);
    return u == v;
}

// 将v->u 这条边加入并查集
void join(int u, int v)
{
    u = find(u); // 寻找u的根
    v = find(v); // 寻找v的根
    if (u == v)
        return; // 如果发现根相同，则说明在一个集合，不用两个节点相连直接返回
    father[v] = u;
}
// ----------------------------------------------------------------------------------------
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    return 0;
}