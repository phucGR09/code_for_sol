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
int t, n, m;
vector<vector<char> > a;
vve row1, row2, col1, col2;
vector<int> dad, level, cnt, mem;
//.................................
void file()
{
    freopen("pcword.inp", "r", stdin);
    freopen("pcword.out", "w", stdout);
}
int union_find(int u)
{
    if(dad[u] == u)
        return u;
    return dad[u] = union_find(dad[u]);
}
void DSU(int u, int v)
{
    u = union_find(u);
    v = union_find(v);
    if(u != v)
    {
        if(level[u] == level[v])
            level[u]++;
        if(level[u] > level[v])
        {
            dad[v] = u;
            cnt[u] += cnt[v];
            cnt[v] = 0;
        }
        else
        {
            dad[u] = v;
            cnt[v] += cnt[u];
            cnt[u] = 0;
        }
    }
}
void solve()
{
    for(int i = 1; i <= n * m; ++i)
        dad[i] = i;
    for(int i=n; i>0; --i)
        for(int j=m; j>0; --j)
    {
        row2[i][j]=(a[i][j]=='#'?0:row2[i][j+1]+1);
        col2[i][j]=(a[i][j]=='#'?0:col2[i+1][j]+1);
    }
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            if(a[i][j]!='#')
            {
                int k = col2[i][j]-col1[i][j];
                if(k>0)
                {
                    int u=(i-1)*m+j;
                    int v=(i+k-1)*m+j;
                    DSU(u, v);
                }
            }
    for(int j = 1; j <= m; ++j)
        for(int i = 1; i <= n; ++i)
            if(a[i][j]!='#')
            {
                int k = row2[i][j] - row1[i][j];
                if(k>0)
                {
                    int u=(i-1)*m+j;
                    int v=(i-1)*m+j+k;
                    DSU(u, v);
                }
            }
    int res = 0;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            if(a[i][j] != '.' && a[i][j] != '#')
            {
                //cout<<i<<' '<<j<<' ';
                int u = union_find((i - 1) * m + j);
                //cout<<u<<' '<<cnt[u]<<'\n';
                if(!mem[u])
                {
                    res += cnt[u];
                    mem[u] = 1;
                }
            }
    cout << res << '\n';
}
void loadinput()
{
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        a.assign(n + 1, vector<char>(m + 1, '.'));
        row1.assign(n + 2, ve(m + 2, 0));
        row2.assign(n + 2, ve(m + 2, 0));
        col1.assign(n + 2, ve(m + 2, 0));
        col2.assign(n + 2, ve(m + 2, 0));
        dad.assign(n * m + 1, 0);
        level.assign(n * m + 1, 0);
        cnt.assign(n * m + 1, 0);
        mem.assign(n * m + 1, 0);
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= m; ++j)
            {
                cin >> a[i][j];
                row1[i][j] = (a[i][j]=='#'?0:row1[i][j - 1] + 1);
                col1[i][j] = (a[i][j]=='#'?0:col1[i - 1][j] + 1);
                cnt[(i - 1)*m + j] = (a[i][j] == '.');
            }
        solve();
    }
}
int main()
{
    faster;
    //file();
    loadinput();
    return 0;
}


