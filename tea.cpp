#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 6e3 + 10;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> r(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> r[i];
    }

    vector<vector<int>> g(n + 1);
    int x, y;
    int v[n + 1];
    memset(v, 0, sizeof v);
    for (int i = 0; i < n - 1; i++)
    {
        cin >> x >> y;
        g[y].push_back(x);
        v[x] = 1;
    }
    int root;
    for (int i = 1; i <= n; i++)
    {
        if (v[i] != 1)
        {
            root = i;
            break;
        }
    }
    function<pair<int, int>(int)> dfs = [&](int x) -> pair<int, int>
    {
        int jp = r[x], not_jp = 0;
        for (int y : g[x])
        {
            auto [come, not_come] = dfs(y);
            not_jp += max(come, not_come);
            jp += not_come;
        }
        return {jp, not_jp};
    };
    auto [jp, not_jp] = dfs(root);
    cout << max(jp, not_jp);
    return 0;
}