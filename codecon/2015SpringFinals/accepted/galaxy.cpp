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

typedef set<string> SetT;

class cell
{
    public :
        string name;
        int x, y, z;
        double r;
        vector<string> nlist;
        SetT path;

        bool operator == (const cell &c) const
        {
            return ((x == c.x) && (y == c.y) && (z == c.z));
        }

        void insert(const cell &c)
        {
            if (dist(c) <= r)
            {
                nlist.push_back(c.name);
            }
        }

        double dist(const cell &c)
        {
            return sqrt(pow((x-c.x),2)+pow((y-c.y),2)+pow((z-c.z),2));
        }
};

void print(const cell &c)
{
    cout << c.name << ","<<c.x<<","<<c.y<<","<<c.z<<","<<c.r;
    for (int i = 0; i < c.nlist.size(); ++i)
        cout << "," << c.nlist[i];
    cout <<endl;
}

typedef map <string, cell> MapT;

MapT p;

cell src, dest;

SetT vis;
typedef pair<int, SetT> PairT;

void traverse(cell &curr)
{
    if (curr.nlist.empty()
        || !curr.path.empty()) {
        return;
    }

    MapT::iterator maxiter = p.end();
    for (int i = 0; i < curr.nlist.size(); ++i)
    {
        if (vis.find(curr.nlist[i]) != vis.end())
            continue;

        vis.insert(curr.nlist[i]);

        MapT::iterator iter = p.find(curr.nlist[i]);

        traverse(iter->second);

        if (maxiter == p.end() 
            || maxiter->second.path.size() < iter->second.path.size())
        {
            maxiter = iter;
        }

        vis.erase(curr.nlist[i]);
    }

    if (maxiter != p.end())
    {
    curr.path = maxiter->second.path;
    curr.path.insert(maxiter->first);
    }
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

        p.insert(make_pair(tmp.name, tmp));
    }

    for (MapT::iterator it = p.begin(); it != p.end(); ++it)
    {
        for (MapT::iterator jt = p.begin(); jt != p.end(); ++jt)
        {
            if (it->first != jt->first) it->second.insert(jt->second);
        }
    }

    SetT max;

    for (MapT::iterator it = p.begin(); it != p.end(); ++it)
    {
        for (MapT::iterator iter = p.begin(); iter != p.end(); ++iter)
        {
            iter->second.path.clear();
        }

        vis.clear();

        vis.insert(it->first);
        traverse(it->second);
        it->second.path.insert(it->first);

        if (max.size() < it->second.path.size())
            max = it->second.path;
    }

    for (SetT::iterator iter = max.begin(); iter != max.end(); ++iter)
    {
        if (iter != max.begin()) cout << ",";

        cout << *iter;
    }

    return 0;
}
