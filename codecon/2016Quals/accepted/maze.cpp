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

        if (steps > 0) return steps+1;
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

    cin >> src.x >> src.y;
    cin >> dest.x >> dest.y;

    fc = maze[src.x][src.y];
    vis.push_back(src);
    cout << traverse(src);

    return 0;
}
