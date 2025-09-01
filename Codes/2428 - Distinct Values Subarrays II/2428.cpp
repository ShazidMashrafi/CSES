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
    ll n, k;
    cin >> n >> k;
    vector<ll>v(n);
    for(auto &i : v)    cin >> i;
    
    map<ll, ll> mp;
    ll l = 0, ct = 0, ans = 0;
    for(ll r = 0; r < n; ++r)  {
        ll e = v[r];
        mp[e]++;
        if(mp[e] == 1) ct++;
        
        while(ct > k) {
            mp[v[l]]--;
            if(mp[v[l]] == 0) ct--;
            l++;
        }
        
        ans += (r - l + 1);
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