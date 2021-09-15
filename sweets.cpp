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
int n;
ll a[101];
ll f[1 << 20];
ll f3[101][501][350];
ll sum = 0;
//.................................
void file()
{
    freopen("sweets.inp", "r", stdin);
    freopen("sweets.out", "w", stdout);
}
void sub2()
{
    ll res = INF;
    ll bitmax = (1 << n);
    for(int i = 1; i < bitmax; ++i)
    {
        ll t = 0;
        for(int j = 0; j < n; ++j)
            if((i >> j) & 1)
                t += a[j + 1];
        if(t <= sum / 3)
            f[i] = t;
        else
        {
            for(int j = 0; j < n; ++j)
                if((i >> j) & 1)
                    f[i] = max(f[i], f[i ^ (1 << j)]);
        }
        ll C = f[i], B = sum - t, A = t - C;
        if(A >= B && B >= C)
            res = min(res, A - C);
    }
    cout << res;
}
ll dp(int i, int A, int B, int C)
{
    if(C > sum / 3)
        return INF;
    if(i > n)
    {
        if(A < B)
            return INF;
        return A - C;
    }
    ll &res = f3[i][C][B];
    if(res != -1)
        return res;
    res = INF;
    res = min(res, dp(i + 1, A + a[i], B, C));
    res = min(res, dp(i + 1, A, B + a[i], C));
    res = min(res, dp(i + 1, A, B, C + a[i]));
    return res;
}
void solve()
{
    for(int i = 1; i <= n; ++i)
        sum += a[i];
    if(n <= 20)
        sub2();
    else
    {
        for(int i = 1; i <= n; ++i)
            for(int j = 0; j <= 500; ++j)
                for(int k = 0; k <= 350; ++k)
                    f3[i][j][k] = -1;
        cout << dp(1, 0, 0, 0);
    }
}
void loadinput()
{
    cin >> n;
    for(int i = 1; i <= n; ++i)
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

