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
    ll n, k;
    cin >> n >> k;
    vector<ll>v(n);
    for(auto &i : v)    cin >> i;

    multiset<ll> lst, rst;
    ll sum_l = 0, sum_r = 0, ans = 0;

    auto balance = [&]() {
        while (sz(lst) > (k + 1) / 2) {
            auto it = prev(lst.end());
            ll val = *it;
            lst.erase(it);
            sum_l -= val;
            rst.insert(val);
            sum_r += val;
        }
        while (sz(lst) < (k + 1) / 2 && !rst.empty()) {
            auto it = rst.begin();
            ll val = *it;
            rst.erase(it);
            sum_r -= val;
            lst.insert(val);
            sum_l += val;
        }
    };
    auto add = [&](ll x) {
        if (lst.empty() || x <= *lst.rbegin()) {
            lst.insert(x);
            sum_l += x;
        } else {
            rst.insert(x);
            sum_r += x;
        }
        balance();
    };
    auto remove = [&](ll x) {
        auto it = lst.find(x);
        if (it != lst.end()) {
            lst.erase(it);
            sum_l -= x;
        } else {
            it = rst.find(x);
            rst.erase(it);
            sum_r -= x;
        }
        balance();
    };

    auto get_cost = [&]() {
        ll m = *lst.rbegin();
        return (sz(lst) * m - sum_l) + (sum_r - sz(rst) * m);
    };

    for (int i = 0; i < k; ++i) {
        add(v[i]);
    }
    cout << get_cost();

    for (int i = k; i < n; ++i) {
        add(v[i]);
        remove(v[i - k]);
        cout << " " << get_cost();
    }
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