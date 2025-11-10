#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// -----------------------欧拉筛------------------------------------------
const int MX = 1e8 + 10;
vector<int> primes;

int initprimes = []()
{
    bool np[MX + 1]{};
    for (int i = 2; i <= MX; i++)
    {
        if (!np[i])
            primes.push_back(i);
        for (int &p : primes)
        {
            if (i * p > MX)
                break;
            np[i * p] = true;
            if (i % p == 0)
                break;
        }
    }
    primes.push_back(MX + 1);
    primes.push_back(MX + 1); // 防止越界
    return 0;
}();

// ----------------------------------------------------------------------------------------
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin >> n >> q;
    while (q--)
    {
        int t;
        cin >> t;
        cout << primes[t - 1] << endl;
    }
    return 0;
}