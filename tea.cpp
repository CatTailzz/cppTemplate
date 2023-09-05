#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 105;
char s[2][MAXN];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    for (int i = 0; i < 2; i++)
        cin >> s[i];
    int ans = 0;
    int pre = 0;
    for (int i = 0; i < strlen(s[0]); i++)
    {
        int cur = (s[0][i] == '0') + (s[1][i] == '0');
        if (cur == 0)
            pre = 0;
        if (cur == 1)
        {
            if (pre == 2)
            {
                ans++;
                pre = 0;
            }
            else
            {
                pre = 1;
            }
        }
        if (cur == 2)
        {
            if (pre == 1)
            {
                ans++;
                pre = 0;
            }
            else if (pre == 0)
            {
                pre = 2;
            }
            else if (pre == 2)
            {
                ans++;
                pre = 1;
            }
        }
    }
    cout << ans << endl;
    return 0;
}