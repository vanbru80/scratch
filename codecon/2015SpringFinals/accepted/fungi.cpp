// Note: if ring inside ring choose outer ring as containing the ring

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int row, col, fc = -1, ic = -2, vc = -3;
vector <vector<int> > maze;
int ncol = -1;
typedef vector<int> VecT;

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

        bool boundary() const
        {
            return (x == 0 || y == 0 || x == (row-1) || y == (col-1));
        }
};

void traverse(const cell &curr, int c)
{
    maze[curr.x][curr.y] = c;

    //int shift[8][2] = {0, 1, 0, -1, 1, 0, -1, 0, -1, -1, -1, 1, 1, 1, 1, -1};
    int shift[8][2] = {-1, -1, -1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1};

    for (int i = 0; i < 8; ++i)
    {
        cell next(curr.x+shift[i][0], curr.y+shift[i][1]);

        if (next.isvalid()
            && fc != maze[next.x][next.y]
            && ic == maze[next.x][next.y])
        {
            traverse(next, c);
        }
    }

    return;
}

bool countRings(const cell &curr, int &seen)
{
    if (maze[curr.x][curr.y] != fc) return false;

    maze[curr.x][curr.y] = vc;

    bool ret = true;

    if (curr.boundary()) ret = false;

    //int shift[8][2] = {0, 1, 0, -1, 1, 0, -1, 0, -1, -1, -1, 1, 1, 1, 1, -1};
    int shift[8][2] = {-1, -1, -1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1};

    for (int i = 0; i < 8; ++i)
    {
        cell next(curr.x+shift[i][0], curr.y+shift[i][1]);

        if (next.isvalid())
        {
            if (seen == -1 && maze[next.x][next.y] >= 0) 
                seen = maze[next.x][next.y];

#if 0
            if (seen != -1 && maze[next.x][next.y] >= 0
                && maze[next.x][next.y] != seen)
            {
                ret = false;
                continue;
            }
#endif

            if (maze[next.x][next.y] == fc
                && countRings(next, seen) == false)
                ret = false;
        }
    }

    return ret;
}

int main()
{
    int len;

    cin >> row >> col >> len;

    if (len == 0) {
        cout << "No colonies";
        return 0;
    }

    maze.resize(row);

    for (int i = 0; i < row; ++i)
    {
        maze[i].resize(col);
        for (int j = 0; j < col; ++j)
        {
            maze[i][j] = fc;
        }
    }

    vector <cell> flist;
    for (int i = 0; i < len; ++i)
    {
        int x, y;
        cin >> x >> y;
        cell tmp(x, y);

        flist.push_back(tmp);
        maze[x][y] = ic;
    }

    for (int i = 0; i < flist.size(); ++i)
    {
        if (maze[flist[i].x][flist[i].y] == ic)
        {
            traverse(flist[i], ++ncol);
        }
    }

    VecT v(ncol+1, 0);

    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            int seen = -1;
            cell c;
            c.x = i; c.y = j;
            if (countRings(c, seen))
            {
                v[seen]++;
            }

        }
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < v.size(); ++i)
    {
        if (i != 0) cout << " ";
        cout << v[i];
    }

    return 0;
}

