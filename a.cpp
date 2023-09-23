#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector<int> nums(5);
    iota(nums.begin(), nums.end(), 0);
    for (auto num : nums)
        cout << num;
    return 0;
}