//Problem        : Scheduling Assistant
//Language       : C++14
//Compiled Using : g++
//Version        : GCC 4.9.1
//Input for your program will be provided from STDIN
//Print out all output from your program to STDOUT

#include <iostream>
#include <string>
#include <algorithm>
#include <climits> 
#include <vector>

using namespace std;

typedef vector<int> VecT;

int main()
{
    
    int d, n;
    cin >> d >> n;

    VecT v(96, 0);

    for (int i = 0; i < n; ++i)
    {
        string s;
        int b;
        cin >> s >> b;
        for (int j = 0; j < b; ++j)
        {
            int a, b;
            cin >> a >> b;
            for (int k = a; k < b; ++k)
                v[k] = 1;
        }

    }

    int begin = -1;
    for (int i = 0; i < v.size(); ++i)
    {
        if (v[i] == 0) 
        {
            if (begin == -1)
                begin = i;

            if ((i-begin+1) >= d)
            {
                cout << begin;
                return 0;
            }
        }
        else
            begin = -1;
    }

    cout << "-1" <<endl;

    return 0;
}
