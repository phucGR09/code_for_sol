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
int n, d;
int a[2001];
ll f[2001];
int pos[2001];
vve ds;

//.................................
void file()
{
    freopen(".inp", "r", stdin);
    freopen(".out", "w", stdout);
}
void solve()
{
    int res=0;
    for(int p=1; p<2*n; ++p)
    {
        ve ds;
        for(int i=1; i<=2*n; ++i)
            f[i]=INF;
        for(int i=1; i<=p; ++i)
        {
            ve h;
            for(int j=max(1, a[i]-d); j<=min(2*n, a[i]+d); ++j)
                if(pos[j]>p)
                h.push_back(pos[j]);
            sort(h.begin(), h.end(), greater<int>());
            for(int j=0; j<h.size(); ++j)
                ds.push_back(h[j]);
        }
        int ans=0;
        for(int i=0; i<ds.size(); ++i)
        {
            int x=lower_bound(f+1, f+2*n+1, ds[i])-f;
            ans=max(ans, x);
            if(f[x]>ds[i])
                f[x]=ds[i];
        }
        res=max(res, ans);
    }
    cout<<res;
}
void loadinput()
{
    cin>>n>>d;
    for(int i=1; i<=2*n; ++i)
        cin>>a[i], pos[a[i]]=i;
}
int main()
{
    faster;
    //file();
    loadinput();
    solve();
    return 0;
}

