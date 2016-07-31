#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

typedef vector<string> List;
typedef map<string, List> Data;

typedef set<string> VisT;

Data g_m;
VisT vis;

int paths(const Data & m, const string &s, const string &d)
{
    if (s == d) return 1;

    Data::const_iterator iter = m.find(s);
    
    if (iter == m.end()) return 0;

    const List &v = iter->second;

    int count = 0;
    for (int i = 0; i < v.size(); ++i)
    {
        if (vis.find(v[i]) != vis.end()) continue;

        vis.insert(v[i]);
        count += paths(m, v[i], d);
        vis.erase(v[i]);
    }

    return count;
}

int main()
{
    int n = 0;

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        string s1, s2;
        cin >> s1 >> s2;
        g_m[s1].push_back(s2);
    }

    vis.insert("JFK");
    cout << paths(g_m, "JFK", "SFO");
    return 0;
}
