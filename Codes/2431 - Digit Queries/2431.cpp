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
    vector<ll> powers(19, 1);
    for(int i = 1; i < 19; ++i) {
        powers[i] = powers[i - 1] * 10;
    }

    ll q;
    cin >> q;
    while(q--){
        ll k;
        cin >> k;
        ll total_digits = 0, digit_len = 0, prev_digits = 0;
        for(int i = 1; i < 19; ++i) {
            total_digits += (powers[i] - powers[i - 1]) * i;
            if(total_digits >= k) {
                digit_len = i;
                break;
            }
            prev_digits = total_digits;
        }

        ll left = powers[digit_len - 1];
        ll right = powers[digit_len] - 1;
        ll ans = 0, pos = 0;
        while(left <= right) {
            ll mid = left + (right - left) / 2;
            ll digit_pos = prev_digits + (mid - powers[digit_len - 1] + 1) * digit_len;
            if(digit_pos < k) {
                left = mid + 1;
            } else {
                ans = mid;
                pos = digit_pos;
                right = mid - 1;
            }
        }

        string num = to_string(ans);
        ll offset = sz(num) - (pos - k) - 1;
        cout << num[offset] << endl;
    }
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