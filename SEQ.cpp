#include<bits/stdc++.h>
using namespace std;

#define ll int64_t
#define fi first
#define se second
#define pb push_back
#define ve vector<ll>
#define vve vector<ve>
#define pa pair<ll, ll>
#define vpa vector<pa>
#define makefill(f, c) memset(f, c, sizeof(f))
#define faster ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

const ll INF = 1e18;
const int mod = 1e9 + 7;
const int nmax = 1e5 + 5;
const double eps = 1e-9;

//.................................
int n;
ll a[2 * nmax];
ll L[2 * nmax];
ll R[2 * nmax];
//.................................
void file()
{
    freopen("SEQ.inp", "r", stdin);
    freopen("SEQ.out", "w", stdout);
}
void solve()
{
    ll res = -INF;
    L[1]=-INF;
    L[2]=-INF;
    R[n]=-INF;
    R[n-1]=-INF;
    for(int i = 3; i <= n; ++i)
    {
        L[i] = a[i] + a[i - 1] + a[i - 2];
        L[i] = max(L[i], L[i] + L[i - 3]);
    }
    for(int i = 3; i <= n; ++i)
        L[i] = max(L[i], L[i - 1]);
    for(int i = n - 2; i > 0; --i)
    {
        R[i] = a[i] + a[i + 1] + a[i + 2];
        R[i] = max(R[i], R[i] + R[i + 3]);
    }
    for(int i = n - 2; i > 0; --i)
        R[i] = max(R[i], R[i + 1]);
    for(int i = 3; i <= n - 3; ++i)
        res = max(res, L[i] + R[i + 1]);
    cout << res;
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


