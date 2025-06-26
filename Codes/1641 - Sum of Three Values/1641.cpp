#include <bits/stdc++.h>
using namespace std;
#ifdef ONLINE_JUDGE
#define dbg(...)
#else
#include <debug.h>
#endif
#define  ll  long long
#define  endl  '\n'
#define  ff  first
#define  ss  second
#define  pb  push_back
#define  sz(x)  (int)(x).size()
#define  all(x)  x.begin(), x.end()
#define  Dpos(n) fixed << setprecision(n)
#define  yn(f)  f? cout<<"YES\n":cout<<"NO\n"
#define  FAST  (ios_base::sync_with_stdio(false), cin.tie(nullptr));
ll power(ll x,ll y,ll m=LLONG_MAX) {ll ans=1;x%=m;while(y){if(y&1)ans=(ans*x)%m;x=(x*x)%m;y>>=1;}return ans;}

void solve()
{
    int n, x;
    cin >> n >> x;
    vector<int> v(n);
    for(auto &&i : v) cin >> i;

    map<int, vector<int>> pos;
    for(int i = 0; i < n; ++i)
        pos[v[i]].push_back(i);

    for(int i = 0; i < n; ++i)
    {
        for(int j = i + 1; j < n; ++j)
        {
            int need = x - v[i] - v[j];
            if(!pos.count(need)) continue;
            
            for(auto k : pos[need])
            {
                if(k == i || k == j) continue;
                cout << i + 1 << " " << j + 1 << " " << k + 1 << endl;
                return;
            }
    
        }
    }
    cout << "IMPOSSIBLE" << endl;
}

signed main()
{
    FAST;
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int TCS = 1;
    // cin >> TCS;
    for (int TC = 1; TC <= TCS; ++TC)
    {
        // cout<<"Case "<<TC<<": ";
        solve();
    }
}