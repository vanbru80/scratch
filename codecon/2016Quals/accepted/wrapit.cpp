#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <climits> 

using namespace std;

void wrapit(string &s, const int len)
{
    int start = 0;
    int last = -1;
    for (int i = 0; i < s.size(); ++i)
    {
        int nchars = (i-start+1);

        if (s[i] == '~')
        {
            cout << s.substr(start, nchars-1) << endl;
            start = i+1;
            last = -1;
            continue;
        }
 
        if (s[i] == ' ') last = i;

        if (nchars > len)
        {
            if (last != -1)
            {
                cout << s.substr(start, last-start) << endl;
                start = last+1;
                last = -1;
            }
        }
    }

    cout << s.substr(start);
}

int main() 
{
    int len = 0;
    stringstream ss;
    string s, s1;

    getline(cin, s1);
    ss << s1;
    ss >> len;

    getline(cin, s);

    wrapit(s, len);
    return 0;
}

