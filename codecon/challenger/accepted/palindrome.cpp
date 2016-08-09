#include <iostream>
#include <string>

using namespace std;

bool isPal(const string &s)
{
    string tmp = string(s.rbegin(), s.rend());
    return (s == tmp);
}

size_t run(const string &s)
{
    string runner;
    string::const_reverse_iterator ri = s.rbegin();
    while(ri != s.rend())
    {
        runner.push_back(*ri);
        string tmp = runner + s;

        if (isPal(tmp))
        {
            return tmp.size();
        }

        ++ri;
    }

    return 2*s.size();
}

int main()
{
    string str;
    cin >> str;

    if (isPal(str)) 
        cout << str.size();
    else
        cout << run(str);

    return 0;
}
