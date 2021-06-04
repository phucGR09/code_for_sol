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

ll n, q;
ll A[2 * nmax];
ll p[2*nmax][18];
ve  mem, done, cc, tt;
vpa path;
vve ck;
stack<ll> ds;
ll t=0;
void get_ck(ll u)
{
    ve tam;
    t++;
    cc[u]=t;
    while(ds.top()!=u)
    {
        cc[ds.top()]=t;
        tam.pb(ds.top());
        ds.pop();
    }
    tam.pb(u);
    ll r=0;
    for(ll i=tam.size()-1; i>=0; --i)
    {
        tt[tam[i]]=r;
        ck[t].pb(tam[i]);
        r++;
    }
}
void get_ds(ll u)
{
    if(done[u])
        return;
    if(mem[u])
    {
        get_ck(u);
        return;
    }
    mem[u]=1;
    ds.push(u);
    get_ds(A[u]);
    done[u]=1;
    return;
}
void build_g(ll u)
{
    if(cc[u]||mem[u])
        return;
    mem[u]=1;
    build_g(A[u]);
    if(cc[A[u]])
        path[u]={1, A[u]};
    else
    {
        path[u]={path[A[u]].fi+1, path[A[u]].se};
        p[u][0]=A[u];
    }
}
int main()
{
    //freopen(".inp", "r", stdin);
    //freopen(".out", "w", stdout);
    faster;
    cin >> n >> q;
    for(ll i = 1; i <= n; ++i)
        cin >> A[i];
    ck.assign(n+1, ve());
    mem.assign(n+1, 0);
    done.assign(n+1, 0);
    cc.assign(n+1, 0);
    path.assign(n+1, pa(0, 0));
    tt.assign(n+1, 0);
    for(ll i = 1; i <= n; ++i)
        if(!mem[i])
        {
            while(!ds.empty()) ds.pop();
            get_ds(i);
        }
    mem.assign(n+1, 0);
    for(ll i=1; i<=n; ++i)
        if(!mem[i])
        build_g(i);
    ll d=1;
    for(ll i=1; i<=18; ++i)
    {
        d*=2;
        for(ll j=1; j<=n; ++j)
        if(path[j].fi>=d)
            p[j][i]=p[p[j][i-1]][i-1];
    }

    for(ll i=1; i<=q; ++i)
    {
        ll x, k;
        cin>>x>>k;
        if(cc[x])
        {
            ll it=(tt[x]+k)%ck[cc[x]].size();
            cout<<ck[cc[x]][it]<<'\n';
        }
        else
        if(k>=path[x].fi)
        {
            ll lap=k-path[x].fi;
            ll it=(tt[path[x].se]+lap)%ck[cc[path[x].se]].size();
            cout<<ck[cc[path[x].se]][it]<<'\n';
        }
        else
        {
            for(ll j=0; j<=18; ++j)
                if((k>>j)&1==1)
                    x=p[x][j];
            cout<<x<<'\n';
        }
    }
}

