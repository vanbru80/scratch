//Problem        : Yet Another Compliance Problem
//Language       : C++14
//Compiled Using : g++
//Version        : GCC 4.9.1
//Input for your program will be provided from STDIN
//Print out all output from your program to STDOUT

#include <iostream>
#include <string>
#include <algorithm>
#include <climits>
#include <map>

using namespace std;

typedef map <char, int> MapT;
map <char, int> cmap;

long long fact(int n)
{
    long long res = 1;
    for (int i = 1; i <= n; ++i)
    {
        res = res*i;
    }
    
    return res;
}

int main() {
    string s;
    cin >> s;
    
    for (int i = 0; i < s.size(); ++i)
    {
        if (cmap.find(s[i]) == cmap.end())
            cmap[s[i]] = 1;
        else
            cmap[s[i]]++;
    }
  
    int count = 0;  
    for (MapT::iterator it = cmap.begin(); it != cmap.end(); ++it)
    {
        if (it->second %2 != 0) count++;
    }
    
    if (count > 1) {
        cout << "0";
        return 0;
    }
    
    long long res = fact(s.size()/2);
    for (MapT::iterator it = cmap.begin(); it != cmap.end(); ++it)
    {
        if (it->second %2 != 0) continue;
        res = res/fact(it->second/2);
    }
    
    cout << res;
    return 0;
}

