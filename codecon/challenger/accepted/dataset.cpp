//Problem        : Matching Datasets
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
#include <vector>
#include <sstream>

using namespace std;

typedef multimap<double, int> MapT;
typedef multimap<int, int> OutMapT;

MapT map1, map2;
OutMapT out;

void tokenize(const string &s, char c, vector<string> &v)
{
    stringstream ss(s);
    for (string each; getline(ss, each, c); v.push_back(each));
}

double getSum(const string &s)
{
    double res = 0;

    vector<string> v;
    tokenize(s, ',', v);

    for(int i = 0; i < v.size(); ++i)
    {
        res += atof(v[i].c_str());
    }

    return res;
}

int main() {
    int n; cin >> n;

    for (int i = 0; i < n; ++i)
    {
        string str;
        cin >> str;
        map1.insert(make_pair(getSum(str), i));
    }

    for (int i = 0; i < n; ++i)
    {
        string str;
        cin >> str;
        map2.insert(make_pair(getSum(str), i));
    }

    MapT::iterator it1 = map1.begin();
    MapT::iterator it2 = map2.begin();
    for ( ; it1 != map1.end(); ++it1, ++it2)
    {
        out.insert(make_pair(it1->second, it2->second));
    }

    OutMapT::iterator it3 = out.begin();
    for ( ; it3 != out.end(); ++it3)
    {
        cout << it3->first << "," << it3->second <<endl;
    }

    return 0;
}


