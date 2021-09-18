#include<bits/stdc++.h>
using namespace std;

#define ll int64_t
#define fi first
#define se second
#define pb push_back
#define ve vector<int>
#define vve vector<ve>
#define pa pair<int, int>
#define vpa vector<pa>
#define makefill(f, c) memset(f, c, sizeof(f))
#define faster ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

const ll INF = 1e18;
const int mod = 1e9 + 7;
const int nmax = 2e5 + 1;
const double eps = 1e-9;

//.................................
int n, d;
int a[1001];
ll f[1001][1001];


//.................................
void file()
{
    freopen(".inp", "r", stdin);
    freopen(".out", "w", stdout);
}

ll dp(int l, int r)
{
    if(l >= r)
        return 0;
    ll &res=f[l][r];
    if(res!=-1)
        return res;
    if(abs(a[l] - a[r]) <= d)
        res = dp(l + 1, r - 1) + 1;
    else
        res = max(dp(l + 1, r), dp(l, r - 1));
    return res;
}
void solve()
{
    makefill(f, -1);
    cout << dp(1, 2 * n);
}
void loadinput()
{
    cin >> n >> d;
    for(int i = 1; i <= 2 * n; ++i)
        cin >> a[i];
}
int main()
{
    faster;
    //file();
    loadinput();
    solve();
    return 0;
}

