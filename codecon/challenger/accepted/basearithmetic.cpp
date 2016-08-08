#include <iostream>
#include <string>
#include <algorithm>
#include <climits> 

using namespace std;

int getdigit(char c)
{
    int x = c - '0';
    if (x >= 0 && x <= 9)
        return x;
    else
        return ((c - 'A') + 10);
}

int getbase(const string &s)
{
    char x = s[0];
    for (int i = 1; i < s.size(); ++i)
    {
        if (x < s[i])
            x = s[i];
    }

    //TODO
    return getdigit(x) + 1;
}

long long base10(const string &s, int base)
{
    long long res = 0;
    long long b = 1;

    for (int i = s.size()-1; i >= 0; --i)
    {
        res += getdigit(s[i])*b;
        b = b * base;
    }

    return res;
}

int main() 
{
    string s1, s2;
    cin >> s1 >> s2;
    long long x, y;
    int base1 = getbase(s1);
    int base2 = getbase(s2);
    cout << (base10(s1, base1) + base10(s2, base2));
    return 0;
}
