#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int row, col, fc;
vector <string> maze;

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

        bool isvalid() const
        {
            return (x >= 0 && x < row && y >= 0 && y < col);
        }
};

cell src, dest;

vector<cell> vis;
vector<cell> path;

int traverse(const cell &curr)
{
    if (curr == dest) return 1;

    int shift[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};

    for (int i = 0; i < 4; ++i)
    {
        cell next(curr.x+shift[i][0], curr.y+shift[i][1]);

        if (!next.isvalid()
            || (std::find(vis.begin(), vis.end(), next) != vis.end())
            || fc != maze[next.x][next.y])
            continue;

        vis.push_back(next);
        int steps = traverse(next);
        vis.pop_back();

        if (steps > 0) 
        {
            path.push_back(next);
            return steps;
        }
    }

    return 0;
}

int main()
{
    cin >> row >> col;

    for (int i = 0; i < row; ++i)
    {
        string s;
        cin >> s;
        maze.push_back(s);
    }

    src.x = 1, src.y = 0;
    dest.x = row-2, dest.y = col-1;

    fc = maze[src.x][src.y];
    vis.push_back(src);
    traverse(src);

    cout << src.x << "," << src.y <<endl;
    for (int i = path.size()-1; i >= 0; --i)
    {
        cout << path[i].x <<","<<path[i].y <<endl;
    }

    return 0;
}
