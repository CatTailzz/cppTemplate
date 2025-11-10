#include <bits/stdc++.h>
using namespace std;

class History
{
private:
    vector<string> history;
    int idx;
    int sz;

public:
    void BrowerHistory(string homepage, int maxCount)
    {
        sz = maxCount;
        history.push_back(homepage);
        idx = 0;
    }

    int visit(string url)
    {
        if (history.size() > idx + 1)
        {
            history.resize(idx + 1);
        }
        if (history.size() == sz)
        {
            history.erase(history.begin());
        }
        else
        {
            idx++;
        }
        history.push_back(url);
        return idx;
    }

    void back()
    {
        if (idx > 0)
        {
            idx--;
        }
    }

    void forward()
    {
        if (idx < history.size() - 1)
        {
            idx++;
        }
    }
};
