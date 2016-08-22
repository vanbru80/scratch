// Create your own template by modifying this file!
#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
     #define debug(args...)            {dbg,args; cerr<<endl;}
#else
    #define debug(args...)              // Just strip off all debug tokens
#endif

struct debugger
{
    template<typename T> debugger& operator , (const T& v)
    {    
        cerr<<v<<" ";    
        return *this;    
    }
} dbg;

int main() 
{
    int r, c;
    char ch;
    cin >> r >> c;

    for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j < c; ++j)
        {
            cin >> ch;
            if (ch == 'C' || ch == 'M' || ch =='Y')
            {
                cout << "#Color" <<endl;
                return 0;
            }
        }
    }

    cout << "#Black&White"<<endl;

    return 0;
}

