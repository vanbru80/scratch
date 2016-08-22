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

typedef long long ll;
typedef vector< vector<ll> > vl;
vl v;
ll n, m, q;

void print()
{
    for (ll i = 0; i < n; ++i)
    {
        for (ll j = 0; j < m; ++j)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}

int main() 
{
    std::ios::sync_with_stdio(false);

    cin >> n >> m >> q;

    v.resize(n);
    for (ll i = 0; i < n; ++i)
    {
        v[i].resize(m,0);
        for (ll j = 0; j < m; ++j)
        {
            cin >> v[i][j];
        }
    }

    for (ll k = 0; k < q; ++k)
    {
        ll a, b, c, d, h, w;
        cin >> a >> b >> c >> d >> h >> w;

        for (ll i = 0; i < h; ++i)
        {
            for (ll j = 0; j < w; ++j)
            {
                swap(v[a+i-1][b+j-1], v[c+i-1][d+j-1]);
            }
        }
    }

    print();

    return 0;
}

