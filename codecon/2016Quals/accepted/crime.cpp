#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

class cell
{
    public : 
        int x, y;
        bool operator == (const cell &c) const
        {
            return ((x == c.x) && (y == c.y));
        }

        cell(int a, int b) : x(a), y(b) {}

        cell() : x(0), y(0) {}
};

vector<cell> v;
vector<cell> vis;

int paths(const cell &curr)
{
    int count = 0;
    for (int i = 0; i < v.size(); ++i)
    {
        if (std::find(vis.begin(), vis.end(), v[i]) != vis.end()
            || (curr.x > v[i].x || curr.y > v[i].y))
            continue;

        vis.push_back(v[i]);
        int n = paths(v[i]);
        vis.pop_back();

        if (n > count) count = n;
    }

    return count+1;
}

int main()
{
    int n = 0;

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int x, y;
        cin >> x >> y;
        v.push_back(cell(x,y));
    }

    vis.push_back(cell(0,0));
    if (std::find(v.begin(), v.end(), cell(0,0)) == v.end())
        cout << paths(vis[0])-1;
    else
        cout << paths(vis[0]);
    return 0;
}
