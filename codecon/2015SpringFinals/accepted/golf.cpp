#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int row, col, fc, maxmoves;
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

int traverse(const cell &curr, int count)
{
    if (count == maxmoves) 
    {
        if (curr == dest)
            return 1;
        else
            return 0;
    }

    int shift[8][2] = {1, 2, -1, 2, 2, 1, 2, -1, 1, -2, -1, -2, -2, 1, -2, -1};

    int paths = 0;
    for (int i = 0; i < 8; ++i)
    {
        cell next(curr.x+shift[i][0], curr.y+shift[i][1]);

        if (!next.isvalid()
            || maze[next.x][next.y] == '-')
            continue;

        paths += traverse(next, count+1);
    }

    return paths;
}

int main()
{
    row = 4; col = 3;
    src.x = 0, src.y = 0;
    dest.x = 2, dest.y = 2;
    maze.push_back("123");
    maze.push_back("456");
    maze.push_back("789");
    maze.push_back("-0-");

    cin >> maxmoves;
    cout << traverse(src, 0);

    return 0;
}
