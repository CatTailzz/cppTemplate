#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// -------------------------Tire树------------------------------------
struct TireNode
{
    TireNode *son[26]{};
    int score = 0; // 也可以是isEnd等
    bool isEnd;
};
void TireInsert(string word, TireNode *root)
{
    TireNode *cur = root;
    for (char c : word)
    {
        if (cur->son[c - 'a'] == nullptr)
            cur->son[c - 'a'] = new TireNode();
        cur = cur->son[c - 'a'];
    }
    cur->isEnd = true;
}
bool Tiresearch(string word, TireNode *root)
{
    TireNode *cur = root;
    for (char c : word)
    {
        cur = cur->son[c - 'a'];
        if (cur == nullptr)
            return false;
    }
    return cur->isEnd;
}

// ----------------------------------------------------------------------------------------
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    return 0;
}