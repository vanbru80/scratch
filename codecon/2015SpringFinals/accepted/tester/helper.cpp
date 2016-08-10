#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string str;
    int row = 0, col = 0;
    vector<pair<int, int> > v;
    while (getline(cin, str))
    {
        for (int i = 0; i < str.size(); ++i)
        {
            if (str[i] == 'x')
                v.push_back(make_pair(row, i));
        }

        row++;
        col = str.length();
    }

    cout << row << " " << col << " " << v.size() <<endl;

    for (int i = 0; i < v.size(); ++i)
        cout << v[i].first << " " << v[i].second << endl;

    return 0;
}
