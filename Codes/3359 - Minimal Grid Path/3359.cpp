#include <bits/stdc++.h>
using namespace std;
#if defined(LOCAL) && !defined(ONLINE_JUDGE)
#include "debug.h"
#else
#define dbg(...)
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
    int n;
    cin >> n;
    vector<string>grid(n);
    for(int i = 0; i < n; i++) {
        cin >> grid[i];
    }
    string ans = "";
    ans += grid[0][0];

    vector<vector<bool>> vis(n, vector<bool>(n, false));
    vis[0][0] = true;

    vector<pair<int,int>> curr;
    curr.pb({0, 0});

    for(int step = 0; step < 2 * n - 2; ++step) {
        char mn = 'Z' + 1;
        vector<pair<int, int>> options;
        
        for(auto [r, c] : curr) {
            if(r + 1 < n && !vis[r + 1][c]) {
                vis[r + 1][c] = true;
                options.pb({r + 1, c});
                mn = min(mn, grid[r + 1][c]);
            }
            if(c + 1 < n && !vis[r][c + 1]) {
                vis[r][c + 1] = true;
                options.pb({r, c + 1});
                mn = min(mn, grid[r][c + 1]);
            }
        }

        ans += mn;
        curr.clear();
        for(auto [r, c] : options) {
            if(grid[r][c] == mn) {
                curr.pb({r, c});
            }
        }
    }
    cout << ans << endl;
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