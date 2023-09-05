#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// -----------------------欧拉筛------------------------------------------
const int MX = 1e6;
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

// -----------------------每个数字的不同质因子个数------------------------------------------
int omega[MX];
int init = []()
{
    for (int i = 2; i < MX; i++)
        if (omega[i] == 0) // 质数
            for (int j = i; j < MX; j += i)
                omega[j]++;
    return 0;
}();
// ----------------------------------------------------------------------------------------
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    return 0;
}