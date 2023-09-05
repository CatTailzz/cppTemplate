
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
ll pow(ll x, int n)
{
    ll res = 1;
    for (; n; n /= 2)
    {
        if (n % 2)
            res = res * x % MOD;
        x = x * x % MOD;
    }
    return res;
}