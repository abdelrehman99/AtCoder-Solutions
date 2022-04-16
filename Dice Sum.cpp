#include <bits/stdc++.h>
using namespace std;
#define fast                 \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define F first
#define FOR(i, n) for (int i = 0; i < (int)n; i++)
#define cin(v, n)                    \
    for (int i = 0; i < (int)n; i++) \
        cin >> v[i];
#define cout(v, n)                   \
    for (int i = 0; i < (int)n; i++) \
        cout << v[i] << (i == n - 1 ? "\n" : " ");
#define WL(t) while (t--)
#define S second
#define PB push_back
#define all(x) x.begin(), x.end()
#define sortall(x) sort(all(x))
#define runtime() cerr << ((double)clock() / CLOCKS_PER_SEC) << endl;
#define MP make_pair
#define llu unsigned long long
#define ret return
#define endl "\n"
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
const ll mod = 998244353, N = 2e6 + 7, M = 2e6 + 7, INF = INT_MAX / 10;
ll powe(ll x, ll y)
{
    x = x % mod, y = y % (mod - 1);
    ll ans = 1;
    while (y > 0)
    {
        if (y & 1)
        {
            ans = (1ll * x * ans) % mod;
        }
        y >>= 1;
        x = (1ll * x * x) % mod;
    }
    return ans;
}

ll n, m, k;
vvl dp;


ll rec (ll sum, ll i)
{
    ll c = 0;
    if (i == n)
    {
        /* for (ll j = 1; i <= m; j++)
        {
            if (sum + j > m) break;
            if (sum + j <= k) (c = (c + 1) % mod);
        } */
        ret (sum <= k ? 1 : 0);
    }
    if (dp[sum][i] != -1 ) ret dp[sum][i];
    for (ll j = 1; j <= m; j++)
    {
        //if (sum + j > m) break;
        c += (rec (sum + j, i + 1) % mod);
    }
    ret dp[sum][i] = (c % mod); 
}

void solve()
{
    cin >> n >> m >> k;
    dp.resize(k + 10000, vl (n + 10, -1));
    ll c = 0;
    for (ll i = 1; i <= m; i++)
    {
        c = (c + rec(i, 1)) % mod;
    }
    cout << c << endl;
    //vl dp(n + 10);
}

signed main()
{
    fast;
    int t = 1;
    //cin >> t;
    WL(t)
    {
        solve();
    }
    runtime();
    return 0;
}
