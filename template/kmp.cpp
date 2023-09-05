#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int gnext[N];

void getnext(string t)
{ /*模板串t*/
    gnext[0] = -1;
    int loc = 0, k = -1;
    while (loc < t.length())
    {
        if (k == -1 || t[loc] == t[k])
        {
            gnext[++loc] = ++k;
        }
        else
            k = gnext[k];
    }
}

int kmp(string s, string t)
{
    int i = 0, j = 0;
    while (i < s.length())
    {
        if (j == -1 || s[i] == t[j])
        {
            i++;
            j++;
        }
        else
        {
            j = gnext[j];
        }
        if (j == t.length())
        {
            // 这里不return而是记录cnt，可以找到多个匹配
            return i - j;
            j = gnext[j];
        }
    }
    return -1;
}

int main()
{
    string s, t;
    cin >> s >> t;
    // 是对模版串t进行next，最后在大串s里找模板串s
    getnext(t);
    kmp(s, t);
    return 0;
}
