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

class Trie {
public:
    struct TrieNode {
        TrieNode* children[26];
        bool isEnd;
        
        TrieNode() {
            isEnd = false;
            for (int i = 0; i < 26; i++)
                children[i] = nullptr;
        }
    };
    
    TrieNode* root;
    
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int index = c - 'a';
            if (!node->children[index])
                node->children[index] = new TrieNode();
            node = node->children[index];
        }
        node->isEnd = true;
    }
};

void solve()
{
    const int MOD = 1e9 + 7;
    string s;
    ll k;
    cin >> s >> k;

    Trie trie;
    for(int i = 0; i < k; ++i) {
        string w;
        cin >> w;
        trie.insert(w);
    }

    ll n = sz(s);
    vector<ll> dp(n + 1, 0);
    dp[0] = 1;
    for(int i = 0; i < n; ++i) {
        if(dp[i] == 0) continue;

        auto node = trie.root;
        for(int j = i; j < n; ++j) {
            int idx = s[j] - 'a';
            if(!node->children[idx]) break;

            node = node->children[idx];
            if(node->isEnd) {
                dp[j + 1] = (dp[j + 1] + dp[i]) % MOD;
            }
        }
    }
    cout << dp[n] << endl;
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