#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

typedef map<string, set<string> > MapT;

typedef set<string> SetT;

MapT flist;
MapT lang;

typedef pair<SetT, SetT> OutT;

template <class T>
void print(const T &p)
{
    typename T::const_iterator iter = p.begin();
    typename T::const_iterator iter_e = p.end();

    for (; iter != iter_e; ++iter)
    {
        if (iter != p.begin())
            cout<<",";

        cout << *iter;
    }
}

OutT doit(const SetT &flist, SetT::const_iterator iter, OutT out)
{
    if (iter == flist.end())
    {
        //print(out.first); cout<<":"; print(out.second);
        //cout<<endl;
        
        return out;
    }

    string frnd = *iter;

    //cout << frnd << endl;

    ++iter;

    OutT tmp1 = doit(flist, iter, out);

    for (SetT::iterator it = lang[frnd].begin(); it != lang[frnd].end(); ++it)
    {
        out.second.insert(*it);
    }

    out.first.insert(frnd);

    OutT tmp2 = doit(flist, iter, out);

    if (tmp1.second.size() > tmp2.second.size())
        return tmp1;
    else if (tmp1.second.size() == tmp2.second.size())
        return (tmp1.first.size() <= tmp2.first.size()) ? tmp1 : tmp2;
    else
        return tmp2;
}

void find(const string &s)
{
    MapT::iterator it = lang.begin();
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
    for (int j = 0; j < d; ++j)
    {
        string s1, s2;
        cin >> s1 >> s2;
        flist[s1].insert(s2);
        flist[s2].insert(s1);
    }

    string person;
    cin >> person;

    find(person);

    OutT tmp, res;
    res = doit(flist[person], flist[person].begin(), tmp);

    SetT::const_iterator iter = res.first.begin();
    SetT::const_iterator iter_e = res.first.end();

    for (; iter != iter_e; ++iter)
    {
        if (iter == res.first.begin())
            cout<<*iter;
        else
            cout<< "," << *iter;
    }

    return 0;
}
