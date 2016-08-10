//Problem        : Basic Encryption
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

typedef vector<long long> VecT;
VecT v;

int main() {
    int n; cin >> n;

    if (n == 1) {
        cout << "MULTIPLE SOLUTIONS";
        return 0;
    }

    v.resize(n);
    long long sum = 0;
    long long max = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
        sum += v[i];
        if (v[i] > max) max = v[i];
    }

    if ((sum % (n-1) != 0)
        || ((sum/(n-1) - max) < 0))
    {
        cout << "NO SOLUTION";
        return 0;
    }

    sum = sum/(n-1);
    for (int i = 0; i < n; ++i)
    {
        cout << sum - v[i] << endl;
    }

    return 0;
}

