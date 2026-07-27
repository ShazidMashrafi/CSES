#include <bits/stdc++.h>
using namespace std;
#if defined(LOCAL) && !defined(ONLINE_JUDGE)
#include <debug.h>
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

const int MOD = 1e9 + 7;
const int N = 1e6 + 10;
vector<ll> fac(N), inv_fac(N);

void precompute()
{
	fac[0] = 1;
	for(int i = 1; i < N; ++i) {
		fac[i] = (fac[i - 1] * i) % MOD;
	}

    inv_fac[N - 1] = power(fac[N - 1], MOD - 2, MOD);
    for(int i = N - 2; i >= 0; --i) {
        inv_fac[i] = (inv_fac[i + 1] * (i + 1)) % MOD;
    }
}

void solve()
{
    int a, b;
    cin >> a >> b;
    ll ans = fac[a];
    ans = (ans * inv_fac[b]) % MOD;
    ans = (ans * inv_fac[a - b]) % MOD;
    cout << ans << endl;
}

signed main()
{
    FAST;
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    precompute();

    int TCS = 1;
    cin >> TCS;
    for (int TC = 1; TC <= TCS; ++TC)
    {
        // cout<<"Case "<<TC<<": ";
        solve();
    }
}