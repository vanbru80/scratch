#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <set>

using namespace std;

typedef set<int> RlistT;

void getNextQuery(vector<int> &input)
{
   std::string str;
   cin >> str;

   // work
   std::istringstream split(str);
   std::vector<std::string> tokens;

   for (std::string each
        ; std::getline(split, each, '-')
        ; )
   {
       stringstream strm;
       strm << each;
       int d;
       strm >> d;
       input.push_back(d);
   }
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
    while (1)
    {
        input.clear();
        getNextQuery(input);
        if (input.empty()) return;

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
            else
                cout << "None" <<endl;

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
    }
}


int main()
{
    doit();
    return 0;
}
