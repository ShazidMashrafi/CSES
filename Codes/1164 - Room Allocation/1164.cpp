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
    ll n, room = 0;
    cin >> n;
    vector< vector<ll> > customer(n, vector<ll>(3));
    for(ll i = 0; i < n; ++i)
    {
        cin >> customer[i][0] >> customer[i][1];
        customer[i][2] = i;
    }
    sort(all(customer));
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    ll ct = 0;
    vector<ll> rooms(n);
    for(auto &v : customer)
    {
        ll a = v[0];
        ll b = v[1];
        ll i = v[2];

        if(!pq.empty() && pq.top().ff < a)
        {
            ll room = pq.top().ss;
            pq.pop();
            pq.push({b, room});
            rooms[i] = room;
        }
        else
        {
            ct++;
            pq.push({b, ct});
            rooms[i] = ct;
        }
    }

    cout << ct << endl;
    for(auto &room : rooms)
        cout << room << " ";
    cout << endl;
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