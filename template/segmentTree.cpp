#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// -------------------------线段树------------------------------------
static constexpr int MX = 4e5 + 5;
int sum[MX];
bool lazy[MX];
// 初始化线段树， o,l,r = 1, 1, n
void build(vector<int> &a, int o, int l, int r)
{
    if (l == r)
    {
        // 维护sum
        sum[o] = a[l - 1];
        return;
    }
    int m = (l + r) / 2;
    build(a, o * 2, l, m);
    build(a, o * 2 + 1, m + 1, r);
    // 维护sum
    sum[o] = sum[o * 2] + sum[o * 2 + 1];
}

void _do(int o, int l, int r) // 向下处理lazy时，如何把lazy tag的影响实例化
{
    sum[o] = r - l + 1 - sum[o];
    lazy[o] = !lazy[o];
}

void update(int o, int l, int r, int L, int R)
{
    if (L <= l && r <= R)
    {
        // lazy
        _do(o, l, r);
        return;
    }
    int m = (l + r) / 2;
    // lazy
    if (lazy[o])
    {
        _do(o * 2, l, m);
        _do(o * 2 + 1, m + 1, r);
        lazy[o] = false;
    }
    if (m >= L)
        update(o * 2, l, m, L, R);
    if (m < R)
        update(o * 2 + 1, m + 1, r, L, R);
    // 维护
    sum[o] = sum[o * 2] + sum[o * 2 + 1];
}

// ----------------------------------------------------------------------------------------
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    return 0;
}