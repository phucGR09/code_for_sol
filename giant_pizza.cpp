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
vve dsk1, dsk2, new_g;
ve mem, num, low, tplt, topo, deg, comp;
stack<ll> ds;
ll t = 0, cur = 0;
map<pa, ll> mp;
void get_tplt(ll u)
{
    tplt[u] = ++cur;
    mem[u] = 1;
    while(ds.top() != u)
    {
        tplt[ds.top()] = cur;
        mem[ds.top()] = 1;
        ds.pop();
    }
    ds.pop();
}
void tarjan(ll u)
{
    ++t;
    num[u] = low[u] =t;
    ds.push(u);
    for(ll i = 0; i < dsk1[u].size(); ++i)
    {
        ll v = dsk1[u][i];
        if(mem[v])
            continue;
        if(num[v])
            low[u] = min(low[u], num[v]);
        else
        {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
    }
    if(num[u] == low[u])
        get_tplt(u);
}
int main()
{
    //freopen(".inp", "r", stdin);
    //freopen(".out", "w", stdout);
    faster;
    cin >> n >> m;
    dsk1.assign(2 * m + 1, ve());
    // dsk2.assign(2*m + 1, ve());
    mem.assign(2 * m + 1, 0);
    num.assign(2 * m + 1, 0);
    low.assign(2 * m + 1, 0);
    tplt.assign(2*m +1, 0);
    topo.assign(2 * m + 1, 0);
    deg.assign(2 * m + 1, 0);
    comp.assign(2 * m + 1, 0);
    new_g.assign(2 * m + 1, ve());
    for(ll i = 1; i <= n; ++i)
    {
        char x, y;
        ll a, b;
        cin >> x >> a >> y >> b;
        ll u = (x == '-' ? 2 * m - a + 1 : a);
        ll v = (y == '-' ? 2 * m - b + 1 : b);
        dsk1[2 * m - u + 1].pb(v);
        dsk1[2 * m - v + 1].pb(u);
        // dsk2[u].pb(2 * m - v + 1);
        // dsk2[v].pb(2 * m - u + 1);
    }
    for(ll i = 1; i <= 2 * m; ++i)
        if(!mem[i])
            tarjan(i);
    for(ll i = 1; i <= 2 * m; ++i)
        for(ll j = 0; j < dsk1[i].size(); ++j)
        {
            ll v = dsk1[i][j];
            if(tplt[i] != tplt[v] && mp.find({tplt[i], tplt[v]}) == mp.end())
            {
                new_g[tplt[i]].pb(tplt[v]);
                deg[tplt[v]]++;
                mp[ {tplt[i], tplt[v]}] = 1;
            }
        }
    queue<ll> q;
    for(ll i = 1; i <= cur; ++i)
        if(deg[i] == 0)
            q.push(i);
    t = 0;
    while(!q.empty())
    {
        ll u = q.front();
        q.pop();
        topo[u] = ++t;
        for(ll i = 0; i < new_g[u].size(); ++i)
        {
            ll v = new_g[u][i];
            if(--deg[v] == 0)
                q.push(v);
        }
    }
    for(ll i = 1; i <= 2 * m; ++i)
        comp[i] = topo[tplt[i]];
    string kq = "";
    for(ll i = 1; i <= m; ++i)
    {
        if(comp[i] == comp[2 * m - i + 1])
        {
            cout << "IMPOSSIBLE";
            return 0;
        }
        kq += (comp[i] > comp[2 * m - i + 1] ? '+' : '-');
    }
    for(ll i=0; i<kq.size(); ++i)
    cout << kq[i]<<' ';

}

