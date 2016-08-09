#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <algorithm>
#include <ctype.h>

using namespace std;

struct lessThan
{
    bool operator()(const string &s1, const string &s2) const
    {
        string tmp1(s1), tmp2(s2);

        transform(s1.begin(), s1.end(), tmp1.begin(), ::tolower);
        transform(s2.begin(), s2.end(), tmp2.begin(), ::tolower);

        return tmp1 < tmp2;
    }
};

typedef map<string, int, lessThan> MapT;

MapT out;

bool isSock(const string &src)
{
    return (src.find("sock") != string::npos);
}

int main()
{
    string s;
    getline(cin, s);

    while (!s.empty())
    {
        if (out.find(s) == out.end())
            out[s] = 1;
        else
            ++(out[s]);

        getline(cin, s);
    }

    MapT::iterator iter = out.begin();
    MapT::iterator iter_e = out.end();

    for (; iter != iter_e; ++iter)
    {
        if (isSock(iter->first))
        {
            cout << (iter->second)/2 << "|" << iter->first << endl;

            if (iter->second%2 == 1 && iter->second > 2)
                cout << "0|" << iter->first << endl;
        }
        else
            cout << (iter->second) << "|" << iter->first << endl;
    }

    return 0;
}

