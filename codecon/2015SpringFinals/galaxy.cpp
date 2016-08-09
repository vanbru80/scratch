#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <stdlib.h>
#include <algorithm>
#include <math.h>
#include <sstream>

using namespace std;

class cell
{
    public :
        string name;
        int x, y, z;
        double r;
        vector<cell> nlist;

        bool operator == (const cell &c) const
        {
            return ((x == c.x) && (y == c.y) && (z == c.z));
        }

        void insert(const cell &c)
        {
            if (dist(c) <= r)
            {
                nlist.push_back(c);
            }
        }

        double dist(const cell &c)
        {
            return sqrt(pow((x-c.x),2)+pow((y-c.y),2)+pow((z-c.z),2));
        }
};

void print(const cell &c)
{
    cout << c.name << ","<<c.x<<","<<c.y<<","<<c.z<<","<<c.r<<endl;
}

struct lessThan
{
    bool operator ()(const cell &c1, const cell &c2) const
    {
        return (c1.name < c2.name);
    }
};

vector <cell> p;

cell src, dest;

typedef set<cell, lessThan> SetT;

SetT vis;
typedef pair<int, SetT> PairT;

PairT traverse(const cell &curr)
{
    PairT max;
    max.first = 0;

    if (curr.nlist.empty()) {
        max.first = 1; max.second.insert(curr);
        return max;
    }

    for (int i = 0; i < curr.nlist.size(); ++i)
    {
        if (curr.name == curr.nlist[i].name) continue;

        if (vis.find(curr) != vis.end())
            continue;

        vis.insert(curr.nlist[i]);

        PairT tmp = traverse(curr.nlist[i]);
        if (max.first < tmp.first) max = tmp;

        vis.erase(curr.nlist[i]);
    }

    max.first++; max.second.insert(curr);

    cout << curr.name <<","<<max.first<<endl;
    return max;
}

enum {X=0, Y, Z, R, N};

int main()
{
    int n;

    string nstr;
    getline(cin, nstr);

    n = atoi(nstr.c_str());

    for (int i = 0; i < n; ++i)
    {
        string str;
        getline(cin, str);

        stringstream ss(str);

        vector<string> out;
        for (string each; getline(ss, each, ','); out.push_back(each));

        cell tmp;
        tmp.x = atoi(out[X].c_str());
        tmp.y = atoi(out[Y].c_str());
        tmp.z = atoi(out[Z].c_str());

        tmp.r = atof(out[R].c_str()); 
        tmp.name = out[N];

        p.push_back(tmp);
    }

    for (int i = 0; i < p.size(); ++i)
    {
        for (int j = 0;  j < p.size(); ++j)
        {
            if (i != j) p[i].insert(p[j]);
        }
    }

    PairT max;
    max.first = 0;

    for (int i = 0; i < p.size(); ++i)
    {
        vis.clear();

        vis.insert(p[i]);
        PairT tmp = traverse(p[i]);

        if (max.first < tmp.first) max = tmp;
    }

    for (SetT::iterator iter = max.second.begin(); iter != max.second.end(); ++iter)
    {
        if (iter != max.second.begin()) cout << ",";

        cout << iter->name;
    }

    return 0;
}
