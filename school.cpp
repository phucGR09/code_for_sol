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
int n, m, q;
int s[2*nmax];
vve dsk;
ve dist;
vpa query;
//.................................
void file()
{
    freopen("school.inp", "r", stdin);
    freopen("school.out", "w", stdout);
}
void dijkstra(int u)
{
    priority_queue<pa, vpa, greater<pa> > q;
    q.push({0, n});
    dist.assign(n+1, INF);
    dist[n]=0;
    while(!q.empty())
    {
        pa top=q.top();
        q.pop();
        if(top.fi!=dist[top.se])
            continue;
        for(int i=0; i<dsk[top.se].size(); ++i)
        {
            int v=dsk[top.se][i];
            if(dist[v]>dist[top.se]+1)
            {
                dist[v]=dist[top.se]+1;
                q.push({dist[v], v});
            }
        }
    }
}
void solve()
{
    dijkstra(n);
    set<pa> ans;
    for(int i=1; i<=n; ++i)
    {
        ll d=i-1+dist[s[i]];
        ans.insert({d, i});
    }
    for(int i=0; i<query.size(); ++i)
    {
        int u=query[i].fi, v=query[i].se;
        pa val1={u-1+dist[s[u]], u};
        pa val2={v-1+dist[s[v]], v};
        ans.erase(ans.find(val1));
        ans.erase(ans.find(val2));
        swap(s[u], s[v]);
        ans.insert({u-1+dist[s[u]], u});
        ans.insert({v-1+dist[s[v]], v});
        pa res=*ans.begin();
        cout<<res.fi<<'\n';
    }
}
void loadinput()
{
    cin>>n>>m>>q;
    dsk.assign(n+1, ve());
    for(int i=1; i<=m; ++i)
    {
        int u, v;
        cin>>u>>v;
        dsk[v].pb(u);
    }
    for(int i=1; i<=n; ++i)
        cin>>s[i];
    for(int i=1; i<=q; ++i)
    {
        int u, v;
        cin>>u>>v;
        query.pb({u, v});
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

