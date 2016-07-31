#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <set>

using namespace std;

typedef set<int> RlistT;

bool getNextQuery(vector<int> &input)
{
    string q;

    if (!(cin >> q)) return false;

    int i = 0, start = 0, val = 0;

    stringstream s1;
    while (++i < q.size() && q[i] != '-');
    s1 << q.substr(start, i);
    s1 >> val;
    input.push_back(val);

    start = i+1;
    stringstream s2;
    while (++i < q.size() && q[i] != '-');
    s2 << q.substr(start, i);
    s2 >> val;
    input.push_back(val);
    
    if (i >= q.size()) return true;

    start = i+1;
    stringstream s3;
    while (++i < q.size() && q[i] != '-');
    s3 << q.substr(start, i);
    s3 >> val;
    input.push_back(val);

    return true;
}

void doit()
{
    int n = 0;
    cin >> n;

    vector<RlistT> slots(32);

    for (int i = 0; i < 32; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            slots[i].insert(j);
        }
    }

    vector<int> input;
    while (getNextQuery(input))
    {
        if (input.size() == 2)
        {
            int ts = input[0]-1, ns = input[1];

            vector<int> rlist;

            RlistT::iterator iter = slots[ts].begin();
            RlistT::iterator iter_e = slots[ts].end();

            for (; iter != iter_e; ++iter)
            {
                bool ins = true;
                for (int i = ts+1; i < ts + ns; ++i)
                {
                    if (slots[i].find(*iter) == slots[i].end())
                    {
                        ins = false;
                        break;
                    }
                }
                if (ins) rlist.push_back(*iter);
            }

            if (!rlist.empty())
            {
                for (int i = 0; i < rlist.size(); ++i)
                {
                    if (i != 0) cout << " ";
                    cout << rlist[i];
                }
                
                cout << endl;
            }

        }
        else
        {
            int rid = input[0], ts = input[1]-1, ns = input[2];

            bool book = true;

            for (int i = ts; i < ts + ns; ++i)
            {
                if (slots[i].find(rid) == slots[i].end())
                {
                    book = false;
                    break;
                }
            }

            if (book)
            {
                cout << "Y" << endl;
                for (int j = ts; j < ts + ns; ++j)
                {
                    slots[j].erase(rid);
                }
            }
            else
                cout << "N" << endl;
        }

        input.clear();
    }
}


int main()
{
    doit();
    return 0;
}
