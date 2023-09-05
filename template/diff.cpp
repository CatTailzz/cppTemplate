#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// -------------------------差分--------------------------------------
int diff[200010];
void insert(int l, int r, int c)
{
    diff[l] += c;
    diff[r + 1] -= c;
}
// 差分数组的下标从1开始
// for (int i = 1; i <= n; i++)
//     insert(i, i, nums[i - 1]);

// 这样得到的diff[i]相当于处理后的nums[i - 1]的值
// diff[i] += diff[i - 1];

// ----------------------------------------------------------------------------------------
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    return 0;
}