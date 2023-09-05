#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// -------------------------数位dp------------------------------------
int n; // 在[1,n] 的数字内找
auto s = to_string(n);
int m = s.length();
vector<vector<int>> memo(m, vector<int>(1 << 10, -1));
// int memo[m][1 << 10];
// memset(memo, -1, sizeof(memo)); // -1 表示没有计算过

// mask 前面填的数字的集合，二进制表示，一般用于限定每个数字只能填一次，没有限制时可以去掉
// is_limit 当前位是否有限制，为true则表示前面每一位都填了最大能填的，当前位会受到s[i]的限制，否则可以填0-9或1-9
// is_num 前面是否全是0，如果为True则当前可以跳过也可以选，否则必须选,也用于限制重复的题
function<int(int, int, bool, bool)> f = [&](int i, int mask, bool is_limit, bool is_num) -> int
{
    if (i == m)
        return is_num; // is_num 为 true 表示得到了一个合法数字
    if (!is_limit && is_num && memo[i][mask] != -1)
        return memo[i][mask];
    int res = 0;
    if (!is_num) // 可以跳过当前数位
        res = f(i + 1, mask, false, false);
    int up = is_limit ? s[i] - '0' : 9;    // 如果前面填的数字都和 n 的一样，那么这一位至多填数字 s[i]（否则就超过 n 啦）
    for (int d = 1 - is_num; d <= up; ++d) // 枚举要填入的数字 d
        if ((mask >> d & 1) == 0)          // d 不在 mask 中,如果不用mask而是相邻位关系，则需要加上!is_num || 表示第一位随便填
            res += f(i + 1, mask | (1 << d), is_limit && d == up, true);
    if (!is_limit && is_num)
        memo[i][mask] = res;
    return res;
};
// return f(0, 0, true, false);
// ----------------------------------------------------------------------------------------
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    return 0;
}