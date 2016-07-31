#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <stdlib.h>
#include <queue>
#include <algorithm>

using namespace std;

typedef map<string, pair<int, set<string> > > MapT;
MapT g;

string dfs(const string &s)
{
    MapT::iterator giter = g.find(s);
    int val = giter->second.first;

    if (giter->second.second.empty()) return s;

    set<string>::iterator iter = giter->second.second.begin();
    set<string>::iterator iter_e = giter->second.second.end();

    set<string> tmp;
    for (; iter != iter_e; ++iter)
    {
        tmp.insert(dfs(*iter));
    }

    iter = tmp.begin();
    iter_e = tmp.end();

    int max = 0;
    MapT::iterator maxiter;
    for (; iter != iter_e; ++iter)
    {
        MapT::iterator it = g.find(*iter);
        if (it->second.first > max) {
            max = it->second.first;
            maxiter = it;
        }
    }

    if ((max - val) >= 3)
    {
        tmp.erase(maxiter->first);
        tmp.insert(giter->first);

        giter->second.second = maxiter->second.second;
        maxiter->second.second = tmp;
        return maxiter->first;
    }
    else
    {
        giter->second.second = tmp;
        return giter->first;
    }
}

vector<set<string> > out;
void bfs(const string &s)
{
    typedef pair<string, int> PairT;
    queue<PairT> q;
    q.push(PairT(s, 0));

    while (!q.empty())
    {
        int level = q.front().second;

        MapT::iterator giter = g.find(q.front().first);

        set<string>::iterator iter = giter->second.second.begin();
        set<string>::iterator iter_e = giter->second.second.end();
 
        for (; iter != iter_e; ++iter)
        {
            q.push(PairT(*iter, level+1));
        }

        if (level >= out.size())
        {
            set<string> tmp;
            out.push_back(tmp);
        }

        out[level].insert(q.front().first);
        q.pop();
    }
}

set <string> visited;

string groot;
void rootdfs(const string &str)
{
    if (visited.find(str) != visited.end())
        return;

    set<string>::iterator iter = g[str].second.begin();
    set<string>::iterator iter_e = g[str].second.end();
    for (; iter != iter_e; ++iter)
    {
        if (visited.find(*iter) == visited.end())
            rootdfs(*iter);
    }

    visited.insert(str);
    groot = str;
}

void findroot()
{
    MapT::iterator iter = g.begin();
    MapT::iterator iter_e = g.end();

    for (; iter != iter_e; ++iter)
    {
        rootdfs(iter->first);
    }
}

int main()
{
    int n;
    cin >> n;

    string last;
    for (int i = 0; i < n; ++i)
    {
        string s; int k, l;
        cin >> s >> k >> l;
        g[s].first = k;
        for (int j = 0; j < l; ++j)
        {
            string t;
            cin >> t;
            g[s].second.insert(t);
        }
        last = s;
    }

    findroot();
    string root = dfs(groot);

    bfs(root);

    for (int level = 0; level < out.size(); ++level)
    {
        set<string>::iterator iter = out[level].begin();
        set<string>::iterator iter_e = out[level].end();

        int count = 0;
        for (; iter != iter_e; ++iter)
        {
            if (count > 0) cout << " ";
            cout << *iter;
            if (count == (out[level].size()-1)) cout  << endl;
            count++;
        }
    }
            
    return 0;
}
