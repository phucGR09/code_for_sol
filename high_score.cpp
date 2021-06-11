#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fi first
#define se second
#define pb push_back
#define mp makepair
#define ve vector<ll>
#define vve vector<ve>
#define pa pair<ll, ll>
#define vpa vector<pa>
#define makefill(f, c) memset(f, c, sizeof(f))
#define faster ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

const ll INF = 1e18;
const ll mod = 1e9 + 7;
const ll nmax = 1e5 + 1;
const double eps = 1e-9;

ll n, m;
vector<vpa> dsk;
vve re_g;
ve dist, preup, mem;

bool dfs(ll u)
{
    if(preup[u])
        return true;
    mem[u]=1;
    for(ll i=0; i<re_g[u].size(); ++i)
    {
        ll v=re_g[u][i];
        if(!mem[v])
        {
            if(dfs(v))
                return true;
        }
    }
    return false;
}
int main()
{
    //freopen(".inp", "r", stdin);
    //freopen(".out", "w", stdout);
    faster;
    cin >> n >> m;
    dsk.assign(n + 1, vpa());
    dist.assign(n + 1, -INF);
    re_g.assign(n+1, ve());
    mem.assign(n+1, 0);
    for(ll i = 1; i <= m; ++i)
    {
        ll x, y, c;
        cin >> x >> y >> c;
        dsk[x].pb({y, c});
        re_g[y].pb(x);
    }
    dist[1] = 0;
    bool fin = false;
    ll step = 0;
    while(!fin)
    {
        preup.assign(n+1, 0);
        step++;
        fin = true;
        for(ll i = 1; i <= n; ++i)
        {
            if(dist[i] == -INF)
                continue;
            for(ll j = 0; j < dsk[i].size(); ++j)
            {
                ll v = dsk[i][j].fi;
                ll c = dsk[i][j].se;
                if(dist[v] < dist[i] + c)
                {
                    fin = false;
                    dist[v] = dist[i] + c;
                    preup[v]=1;
                }
            }
        }
        if(step>n)
            fin=true;
    }
    if(step<=n)
        cout<<dist[n];
    else
    {
        if(dfs(n))
            cout<<-1<<' ';
        else
            cout<<dist[n]<<' ';
    }

}

