#include<iostream>
#include<string>
#include<map>

using namespace std;

typedef map<string, int> SetT;

SetT out;

bool isPal(const string &str)
{
    string rev = string(str.rbegin(), str.rend());

    return (str == rev);
}

int main()
{

    int n;
    cin >> n;

    int count = 0;
    for (int i = 0; i < n; ++i)
    {
        string str;
        cin >> str;

        if (isPal(str)) continue;

        string rev = string(str.rbegin(), str.rend());
        if (out.find(rev) != out.end())
        {
            count++;
            out[rev]--;
            if (out[rev] == 0) out.erase(rev);
        }
        else
        {
            if (out.find(str) == out.end())
                out[str] = 1;
            else
                out[str]++;
        }
    }

    if (!out.empty())
        cout << "-1";
    else
        cout << count;

    return 0;
}
