#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <stdlib.h>

using namespace std;

vector<int> nums;
vector<char> ops;
typedef map<char, int> MapT;
MapT pmap;

bool isOp(char c)
{
    return (c == '+' || c == '-' || c == '/' || c == '*');
}

int calc(int a, int b, char c)
{
    switch(c)
    {
        case '+' : return a+b;
        case '-': return a-b;
        case '/': return a/b;
        case '*': return a*b;
    }

    return 0;
}

void process()
{
    char c = ops.back();

    ops.pop_back();

    int a = nums.back();

    nums.pop_back();

    int b = nums.back();

    nums.pop_back();

    int d = calc(b,a,c);

    nums.push_back(d);
}

void initPrec()
{
    pmap.insert(MapT::value_type('*', 1));
    pmap.insert(MapT::value_type('+', 2));
    pmap.insert(MapT::value_type('/', 3));
    pmap.insert(MapT::value_type('-', 4));
}

int main()
{
    string s;
    cin >> s;

    initPrec();

    string n;

    for (int i = 0; i < s.size(); ++i)
    {
        if (isOp(s[i]))
        {
            nums.push_back(atoi(n.c_str()));
            n.clear();
            while (!ops.empty() && (pmap[s[i]] <= pmap[ops.back()]))
                process();
            ops.push_back(s[i]);
        }
        else
        {
            n.push_back(s[i]);
        }
    }

    nums.push_back(atoi(n.c_str()));

    while(!ops.empty())
        process();

    cout << nums.back();

    nums.pop_back();

    return 0;
}
