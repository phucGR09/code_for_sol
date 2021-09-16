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
int n, m;
ll dist[21][21];
int deg[21];
ll f[1 << 20];
ll sum = 0;
//.................................
void file()
{
    freopen("PACMAN.inp", "r", stdin);
    freopen("PACMAN.out", "w", stdout);
}
void solve()
{
    for(int k = 1; k <= n; ++k)
        for(int u = 1; u <= n; ++u)
            for(int v = 1; v <= n; ++v)
                if(k != u && k != v && u != v)
                    dist[u][v] = min(dist[u][v], dist[u][k] + dist[k][v]);
    for(int i=2; i<=n; ++i)
        if(dist[1][i]>=INF&&deg[i]>0)
    {
        cout<<-1;
        return;
    }
    int cnt = 0;
    ve cur;
    for(int i = 1; i <= n; ++i)
        if(deg[i] % 2)
        {
            cnt++;
            cur.pb(i);
        }
    if(cnt==0)
    {
        cout<<sum;
        return;
    }
    for(int i = 0; i < (1 << cnt); ++i)
        f[i] = INF;
    for(int i = 0; i < cnt; ++i)
        for(int j = i + 1; j < cnt; ++j)
        {
            int mark = (1 << i) + (1 << j);
            f[mark] = dist[cur[i]][cur[j]];
        }
    for(int mark = 0; mark < (1 << cnt); ++mark)
    {
        for(int i = 0; i < cnt; ++i)
            if((mark >> i) & 1)
                for(int j = i + 1; j < cnt; ++j)
                    if((mark >> j) & 1)
                        f[mark] = min(f[mark], f[(mark ^ (1 << i)) ^ (1 << j)] + dist[cur[i]][cur[j]]);
    }
    cout << sum + f[(1 << cnt) - 1];
}
void loadinput()
{
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            dist[i][j] = INF;
    for(int i = 1; i <= m; ++i)
    {
        ll u, v, c;
        cin >> u >> v >> c;
        sum += c;
        dist[u][v] = min(dist[u][v], c);
        dist[v][u] = min(dist[v][u], c);
        deg[u]++, deg[v]++;
    }
}
int main()
{
    faster;
    //file();
    loadinput();
    solve();
    return 0;
}
