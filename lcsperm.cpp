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
int n, k;
int a[5*nmax];
int b[5*nmax];
vve pos;
ll f[5*nmax];

//.................................
void file()
{
    freopen(".inp", "r", stdin);
    freopen(".out", "w", stdout);
}
void solve()
{
    ve ds;
    pos.assign(n+1, ve());
    for(int i=n*k; i>0; --i)
        pos[a[i]].push_back(i);
    for(int i=1; i<=n*k; ++i)
    {
        for(int j=0; j<pos[b[i]].size(); ++j)
            ds.push_back(pos[b[i]][j]);
    }
    for(int i=1; i<=n*k; ++i)
        f[i]=INF;
    int res=0;
    for(int i=0; i<ds.size(); ++i)
    {
        int x=lower_bound(f+1, f+n*k+1, ds[i])-f;
        res=max(res, x);
        if(f[x]>ds[i])
            f[x]=ds[i];
    }
    cout<<res;
}
void loadinput()
{
    cin>>n>>k;
    for(int i=1; i<=n*k; ++i)
        cin>>a[i];
    for(int i=1; i<=n*k; ++i)
        cin>>b[i];
}
int main()
{
    faster;
    //file();
    loadinput();
    solve();
    return 0;
}

