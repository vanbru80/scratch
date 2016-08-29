#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
//#include <unordered_map>
#include <cmath>

using namespace std;

long long row, col;

typedef pair<long long, vector<string> > PairT;

vector< vector<long long> > grid;

PairT ZERO;

void print()
{
    for (long long i = 0; i < row; ++i)
    {
        for (long long j = 0; j < col; ++j)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }

    return;
}

PairT solve(long long n, long long c)
{
    if (n < 0) return ZERO;

    vector<PairT> v;
    v.resize(n+1, ZERO);

    for (long long i = 0; i <= n; ++i)
    {
        if (i <= 9)
            v[i].first = 1;
    }

    for (long long i = 1; i < c; ++i)
    {
        for (long long j = n; j >= 0; --j)
        {
            for (long long k = 1; k <= 9; ++k)
                if (j >= k)
                    v[j].first += v[j-k].first;
        }
    }

    if (v[n].first == 1)
    {
        if (c == 1)
            v[n].second.push_back(std::string(1, '0'+n));
        else if (n == 0)
            v[n].second.push_back(std::string(c, '0'));
        else
            v[n].second.push_back(std::string(c, '9'));
    }

    return v[n];
}

PairT perm()
{
    long long n = grid[0][0];
    long long c = row*col;

    for (long long i = 0; i < row; ++i)
    {
        for (long long j = 0; j < col; ++j)
        {
            if (n != grid[i][j])
                return ZERO;
        }
    }

    return solve(n, c);
}

bool findBad(long long &bi, long long &bj)
{
    long long sum = 0;
    for (long long i = 0; i < row; ++i)
    {
        for (long long j = 0; j < col; ++j)
        {
            sum += grid[i][j];
        }
    }

    if (((sum+1)%(row+col-1) != 0)
        && ((sum-1)%(row+col-1) != 0))
    {
        return false;
    }

    sum = (sum+1)/(row+col-1);

    for (long long i = 0; i < row; ++i)
    {
        for (long long j = 0; j < col; ++j)
        {
            long long srow = 0, scol = 0;
            for (long long r = 0; r < row; ++r)
            {
                for (long long c = 0; c < col; ++c)
                {
                    if (r == i)
                        srow += grid[r][c];
                    if (c == j)
                        scol += grid[r][c];
                }
            }

            if (((srow-sum)%(row-1) != 0)
                && ((scol-sum)%(col-1) != 0))
            {
                bi = i; bj = j;
                return true;
            }
        }
    }

    return false;
}

PairT computeGrid()
{
    PairT res(ZERO);

    long long sum = 0;
    for (long long i = 0; i < row; ++i)
    {
        for (long long j = 0; j < col; ++j)
        {
            sum += grid[i][j];
        }
    }

    if ((sum%(row+col-1)) != 0)
    {
        return ZERO;
    }

    sum = sum/(row+col-1);

    for (long long i = 0; i < row; ++i)
    {
        res.second.push_back("");
        for (long long j = 0; j < col; ++j)
        {
            long long srow = 0, scol = 0;
            for (long long r = 0; r < row; ++r)
            {
                for (long long c = 0; c < col; ++c)
                {
                    if (r == i)
                        srow += grid[r][c];
                    if (c == j)
                        scol += grid[r][c];
                }
            }

            if (((srow-sum)%(row-1) != 0)
                || ((scol-sum)%(col-1) != 0))
            {
                return ZERO;
            }

            srow = (srow-sum)/(row-1);
            scol = (scol-sum)/(col-1);

            long long val = (srow+scol)-grid[i][j];

            if (val < 0 || val > 9)
            {
                return ZERO;
            }

            res.second[i].push_back('0'+val);
        }
    }

    res.first = 1;
    return res;
}

PairT solveGrid()
{
    if (row == 1 || col == 1)
        return perm();
    else
        return computeGrid();
}

void run()
{
    PairT res(ZERO);
    long long shift[2] = {-1, 1};

    bool doit = true;
    long long r = -1, c = -1;
    if (row > 2 && col > 2)
    {
        doit = findBad(r, c);
    }

    if (doit)
    {
        for (long long i = 0; i < row; ++i)
        {
            for (long long j = 0; j < col; ++j)
            {
                if (r != -1 && c != -1 && i != r && c != j)
                    continue;

                for (long long k = 0; k < 2; ++k)
                {
                    grid[i][j] += shift[k];

                    PairT tmp = solveGrid();
                    res.first += tmp.first;
                    if (res.second.empty())
                        res.second = tmp.second;

                    grid[i][j] -= shift[k];
                }
            }
        }
    }

    if (res.first == 1)
    {
        for (long long i = 0; i < res.second.size(); ++i)
            cout<<res.second[i]<<endl;
    }
    else
        cout << (res.first)%10007 <<" SOLUTIONS";
}

int main()
{
    cin >> row >> col;

    grid.resize(row);

    for (long long i = 0; i < row; ++i)
    {
        grid[i].resize(col);
        for (long long j = 0; j < col; ++j)
        {
            cin >> grid[i][j];
        }
    }

    ZERO.first = 0;

#if 0
    if (row == 1 && col == 1)
    {
        if (grid[0][0] == 0)
            cout << "1";
        else if (grid[0][0] == 9)
            cout << "8";
        else if (grid[0][0] >= 0 && grid[0][0] <= 8)
            cout << "2 SOLUTIONS";
        else
            cout << "0 SOLUTIONS";
        return 0;
    }
#endif

    run();

    return 0;
}
