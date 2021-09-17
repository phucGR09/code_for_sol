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
const int nmax = 1e6 + 5;
const double eps = 1e-9;

//.................................
int n, m, q;
int deg[10001];
int T[10001];
int mem[10001];
int ans[nmax];
vve dsk;
ve dist;
vector<pair<pa, int> > ques;
//.................................
void file()
{
    freopen("SPATH.inp", "r", stdin);
    freopen("SPATH.out", "w", stdout);
}
void bfs(int u)
{
    dist.assign(n, -1);
    dist[u] = 0;
    int L = n - 1;
    queue<int> q;
    q.push(u);
    while(!q.empty())
    {
        int x = q.front();
        q.pop();
        for(int i = 0; i < dsk[x].size(); ++i)
        {
            int y = dsk[x][i];
            if(dist[y] == -1)
                mem[y] = 0;
        }
        int i = 0;
        while(i <= L)
        {
            if(T[i]!=x&&mem[T[i]])
            {
                dist[T[i]] = dist[x] + 1;
                q.push(T[i]);
                swap(T[i], T[L]);
                L--;
                continue;
            }
            i++;
        }
        for(int i = 0; i < dsk[x].size(); ++i)
            mem[dsk[x][i]] = 1;
    }
}
void solve()
{
    sort(ques.begin(), ques.end());
    for(int i = 0; i < n; ++i)
        sort(dsk[i].begin(), dsk[i].end());
    for(int i = 0; i < n; ++i)
        T[i] = i, mem[i] = 1;
    int i = 0;
    while(i < ques.size())
    {
        int u = ques[i].fi.fi;
        if(deg[u] >= (n + 1) / 2)
        {
            bfs(u);
            while(i < ques.size() && ques[i].fi.fi == u)
            {
                int v = ques[i].fi.se;
                int it = ques[i].se;
                if(u==v)
                {
                    ans[it]=0;
                    i++;
                    continue;
                }
                ans[it] = dist[v];
                i++;
            }
            continue;
        }
        else
        {
            while(i < ques.size() && ques[i].fi.fi == u)
            {
                int v = ques[i].fi.se;
                int it = ques[i].se;
                if(u==v)
                {
                    ans[it]=0;
                    i++;
                    continue;
                }
                int x = lower_bound(dsk[u].begin(), dsk[u].end(), v) - dsk[u].begin();
                ans[it] = ((x >= dsk[u].size() || dsk[u][x] != v) ? 1 : 2);
                i++;
            }
            continue;
        }
    }
    for(int i = 1; i <= q; ++i)
        cout << ans[i] << '\n';
}
void loadinput()
{
    cin >> n >> m;
    dsk.assign(n, ve());
    for(int i = 1; i <= m; ++i)
    {
        int u, v;
        cin >> u >> v;
        dsk[u].pb(v);
        dsk[v].pb(u);
        deg[u]++;
        deg[v]++;
    }
    cin >> q;
    for(int i = 1; i <= q; ++i)
    {
        int x, y;
        cin >> x >> y;
        if(deg[x] < deg[y])
            swap(x, y);
        ques.pb({{x, y}, i});
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

