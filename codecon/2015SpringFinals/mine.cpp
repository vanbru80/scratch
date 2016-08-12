#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <stdlib.h>
#include <algorithm>
#include <unordered_map>
#include <cmath>

using namespace std;

long long row, col;

typedef map<long long, int> MapT;
typedef pair<long long, string> PairT;

vector< vector<long long> > grid;
vector< vector<long long> > out;
vector< vector<PairT> > v;

PairT solve(long long n, long long c)
{
    if (v[n][c-1].first != -1) return v[n][c-1];

    //PairT res = make_pair(0, "");
    if (c == 1) { 
        if (n <= 9 && n >= 0) {
            v[n][c-1].first = 1;
            v[n][c-1].second = std::string(1, '0'+n);
        }
        else {
            v[n][c-1].first = 0;
        }
#if 0
        if (n <= 9) {
            res.first = 1;
            res.second = std::string(1, '0'+n);
        }
#endif
    }
    else
    {
        for (long long i = 0; i <= 9; ++i)
        {
            if (n >= i)
            {
                PairT val = solve(n-i, c-1);
                if (val.first > 0)
                {
                    if (v[n][c-1].first == -1)
                        v[n][c-1].first = val.first;
                    else
                        v[n][c-1].first += val.first;
                    if (v[n][c-1].second.empty())
                    {
                        v[n][c-1].second = std::string(1, '0'+i) + val.second;
                    }
                    //res.first += val.first;
                    //res.second = std::string(1, '0'+i) + val.second;
                }
            }
        }
    }

    return v[n][c-1];
    //return res;
}

void perm()
{
    long long first = -1, second = -1, c = 0;

    MapT cmap;

    for (long long i = 0; i < row; ++i)
    {
        for (long long j = 0; j < col; ++j)
        {
            ++c;
            MapT::iterator iter = cmap.find(grid[i][j]);
            if (iter != cmap.end())
                (iter->second)++;
            else
                cmap.insert(make_pair(grid[i][j], 1));
        }
    }

    bool ret = false;
    if (cmap.size() == 2)
    {
        MapT::iterator it1 = cmap.begin();
        MapT::iterator it2 = it1;
        it2++;

        ret = ((abs((it1->first)-(it2->first)) == 1)
                && (it1->second == c-1 || it2->second == c-1));
        if (it1->second == c-1)
        {
            first = it1->first;
            if (c == 2)
            second = it2->first;
        }
        else
        {
            first = it2->first;
            if (c == 2)
            second = it1->first;
        }

    }
    else if (c == 1) 
    {
        ret = true;
        first = grid[0][0]+1;
        if (first >= 0 && first <= 9)
            second = grid[0][0]-1;
        else
            first = grid[0][0]-1;
    }

    if (!ret)
    {
        cout << "0 SOLUTIONS";
        return;
    }

    int n = max(first+1, second+1);
    v.resize(n);
    for (long long i = 0; i < n; ++i) 
        v[i].resize(c, make_pair(-1, ""));

    PairT res = solve(first, c);
    if (second != -1)
    {
        PairT res2 = solve(second, c);
        if (res2.first > 0)
        {
            if (res.first == 0)
                res = res2;
            else
                res.first = res.first + res2.first;
        }
    }

    if (res.first == 1)
        cout << res.second;
    else
        cout << (res.first)%10007 <<" SOLUTIONS";
}

void computeGrid()
{
    long long sum = 0;
    for (long long i = 0; i < row; ++i)
    {
        for (long long j = 0; j < col; ++j)
        {
            sum += grid[i][j];
        }
    }

    long long offset = -1;
    if ((sum+1)%(row+col-1) == 0) 
    {
        sum = (sum+1)/(row+col-1);
        offset = 1;
    }
    else if ((sum-1)%(row+col-1) == 0) 
        sum = (sum-1)/(row+col-1);
    else
    {
        cout << "0 SOLUTIONS" <<endl;
        return;
    }

    for (long long i = 0; i < row; ++i)
    {
        for (long long j = 0; j < col; ++j)
        {
            long long tmp = 0;
            for (long long r = 0; r < row; ++r)
            {
                for (long long c = 0; c < col; ++c)
                {
                    if (r == i || c == j)
                        tmp += grid[r][c];
                }
            }

            tmp += grid[i][j];

            if (tmp%2 != 0) tmp = tmp + offset;

            out[i][j] = (tmp/2) - (sum + grid[i][j]);

            if (out[i][j] < 0 || out[i][j] > 9)
            {
                cout << "0 SOLUTIONS" <<endl;
                return;
            }
        }
    }

    for (long long i = 0; i < row; ++i)
    {
        for (long long j = 0; j < col; ++j)
        {
            cout <<out[i][j];
        }
        cout<<endl;
    }

}

int main()
{
    cin >> row >> col;

    grid.resize(row);
    out.resize(row);

    for (long long i = 0; i < row; ++i)
    {
        grid[i].resize(col);
        out[i].resize(col);
        for (long long j = 0; j < col; ++j)
        {
            cin >> grid[i][j];
        }
    }

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

    if (row == 1 || col == 1)
    {
        perm();
        return 0;
    }

    computeGrid();

    return 0;
}
