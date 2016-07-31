#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <stdlib.h>
#include <queue>
#include <algorithm>

using namespace std;

map<string, set<string> > MapT;

set<string> SetT;

SetT f;
MapT lang;

SetT out;

SetT void doit(const SetT &flist, SetT::const_iterator iter, SetT lset)
{
    if (iter == flist.end())
        return;

    string frnd = *iter;

    ++iter;

    SetT tmp1 = doit(flist, iter, lset);

    if (tmp1.size() > lang

    SetT tmp1;
    for (SetT::iterator it = lang[frnd].begin(); it != lang[frnd].end(); ++it)
    {
        lset.insert(*it);
    }

}

void find(const string &s)
{
    SetT::iterator it = lang.begin();
    for ( ; it != lang.end(); ++it)
    {
        if (s != it->first)
        {
            SetT::iterator iter = lang[s].begin();
            for (; iter != lang[s].end(); ++iter)
            {
                it->second.erase(*iter);
            }
        }
    }

}

int main()
{
    int n, d;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        string s1, s2;
        cin >> s1 >> s2;
        lang[s1].insert(s2);
    }

    cin >> d;
    for (i = 0; i < d; ++i)
    {
        string s1, s2;
        cin >> s1 >> s2;
        f[s1].insert(s2);
        f[s2].insert(s1);
    }

    return 0;
}
