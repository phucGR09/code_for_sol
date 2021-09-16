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
int n, m, k;
int mtk[1001][1001];
ll dist[1001][1001];
int place[16];
ll f[16][40000];
//.................................
void file()
{
    freopen("TOUR.inp", "r", stdin);
    freopen("TOUR.out", "w", stdout);
}
void dijkstra(int u)
{
    for(int i = 1; i <= n; ++i)
        if(i != u)
            dist[u][i] = INF;
    priority_queue<pa, vpa, greater<pa> > q;
    q.push({0, u});
    while(!q.empty())
    {
        pa top = q.top();
        q.pop();
        if(top.fi != dist[u][top.se])
            continue;
        for(int v = 1; v <= n; ++v)
            if(mtk[top.se][v])
            {
                int c = mtk[top.se][v];
                if(dist[u][v] > dist[u][top.se] + c)
                {
                    dist[u][v] = dist[u][top.se] + c;
                    q.push({dist[u][v], v});
                }
            }
    }
}

ll dp(int it, int mask)
{
    int u = (it == 0 ? 1 : place[it]);
    if(mask == ((1 << k) - 1))
        return dist[u][1];
    ll &res = f[it][mask];
    if(res!=-1)
        return res;
    res=INF;
    for(int i = 0; i < k; ++i)
        if(!((mask >> i) & 1))
        {
            int v = place[i + 1];
            if(dist[u][v]==INF)
                continue;
            res = min(res, dp(i + 1, mask|(1<<i))+dist[u][v]);
        }
    return res;
}
void solve()
{
    dijkstra(1);
    for(int i = 1; i <= k; ++i)
        dijkstra(place[i]);
    makefill(f, -1);
    ll res=dp(0, 0);
    if(res>=INF)
        cout<<-1;
    else
        cout<<res;
}
void loadinput()
{
    cin >> n >> m >> k;
    for(int i = 1; i <= k; ++i)
        cin >> place[i];
    for(int i = 1; i <= m; ++i)
    {
        int u, v, c;
        cin >> u >> v >> c;
        mtk[u][v] = c;
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
