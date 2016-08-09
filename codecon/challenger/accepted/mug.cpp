#include<iostream>
#include<string>
#include<set>

using namespace std;

typedef set<string> SetT;

SetT out;

int main()
{

    out.insert("White");
    out.insert("Black");
    out.insert("Blue");
    out.insert("Red");
    out.insert("Yellow");

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        string s;
        cin >> s;
        out.erase(s);
    }

    cout << *(out.begin());

    return 0;
}
