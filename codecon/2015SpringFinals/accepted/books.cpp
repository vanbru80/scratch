#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <sstream>

using namespace std;

typedef map<string, set<string> > MapT;

typedef set<string> SetT;

MapT flist;
MapT books;

SetT vis;

int sep = 0;

void doit(const string &s, SetT &blist, int count)
{
    if (count >= sep) return;

    for (SetT::iterator it = flist[s].begin(); it != flist[s].end(); ++it)
    {
        if (vis.find(*it) != vis.end()) continue;

        blist.insert(books[*it].begin(), books[*it].end());

        vis.insert(*it);
        doit(*it, blist, count+1);
        vis.erase(*it);
    }

    return;
}

void find(const string &s)
{
    MapT::iterator it = books.begin();
    for ( ; it != books.end(); ++it)
    {
        if (s != it->first)
        {
            SetT::iterator iter = books[s].begin();
            for (; iter != books[s].end(); ++iter)
            {
                it->second.erase(*iter);
            }
        }
    }

}

int main()
{
    string person;
    getline(cin, person);
    cin >> sep;

    int d, n;
    cin >> d >> n;
    string tmp;
    getline(cin, tmp);
    for (int j = 0; j < d; ++j)
    {
        string s;
        getline(cin, s);
        istringstream ss(s);

        string s1, s2;
        getline(ss, s1, '|');
        getline(ss, s2, '|');
        flist[s1].insert(s2);
        flist[s2].insert(s1);
    }

    for (int i = 0; i < n; ++i)
    {
        string s1, s2;
        getline(cin, s1);
        istringstream ss(s1);

        getline(ss, s1, '|');

        for (string each; getline(ss, each, '|'); books[s1].insert(each));
    }

    find(person);

    SetT res;
    vis.insert(person);
    doit(person, res, 0);

    cout << res.size() << endl;

    return 0;
}
