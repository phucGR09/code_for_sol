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
int n, m;
int dad[19][nmax], level[19][nmax];
//.................................
void file()
{
    freopen("CONTACT.inp", "r", stdin);
    freopen("CONTACT.out", "w", stdout);
}
ll power(int x, int k)
{
    if(k == 1)
        return x;
    ll res = power(x, k / 2);
    if(k % 2 == 0)
        return (res * res) % mod;
    else
        return (res * (res * x) % mod) % mod;
}
int union_find(int u, int k)
{
    if(dad[k][u] == u)
        return u;
    return dad[k][u] = union_find(dad[k][u], k);
}
void DSU(int u, int v, int k)
{
    u = union_find(u, k);
    v = union_find(v, k);
    if(u != v)
    {
        if(level[k][u] == level[k][v])
            level[k][u]++;
        if(level[k][u] > level[k][v])
            dad[k][v] = u;
        else
            dad[k][u] = v;
    }
}
void solve()
{
    for(int k = 18; k > 0; --k)
        for(int i = 1; i <= n; ++i)
        {
            int u = union_find(i, k);
            if(u != i)
            {
                DSU(u, i, k - 1);
                DSU(u + (1 << (k - 1)), i + (1 << (k - 1)), k - 1);
            }
        }
    int cnt = 0;
    for(int i = 1; i <= n; ++i)
    {
        int u = union_find(i, 0);
        if(u == i)
            cnt++;
    }
    cout << power(2, cnt);
}
void loadinput()
{
    cin >> n >> m;
    for(int k = 0; k < 19; ++k)
        for(int i = 1; i <= n; ++i)
            dad[k][i] = i;
    for(int i = 1; i <= m; ++i)
    {
        int p, q, l;
        cin >> p >> q >> l;
        if(p > q)
            swap(p, q);
        int t = 0;
        for(int j = 0; j < 19; ++j)
            if((l >> j) & 1)
            {
                DSU(p + t, q + t, j);
                t += (1 << j);
            }
    }
}
int main()
{
    faster;
    file();
    loadinput();
    solve();
    return 0;
}


