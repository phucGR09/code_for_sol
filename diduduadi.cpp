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
struct Data
{
    char ch;
    int p, d, t;
};
Data que[150001];
int sub, t, n, m, q;
int cnt[150001];
int realcnt[150001];
int high[150001];
vector<vector<pa> > ds;

//.................................
void file()
{
    freopen("diduduadi.inp", "r", stdin);
    freopen("diduduadi.out", "w", stdout);
}
void solve()
{
    int play=0;
    for(int i = 1; i <= n; ++i)
    {
        ds[i].clear();
        high[i] = 0;
    }
    for(int i = 0; i <= m; ++i)
        cnt[i] = 0, realcnt[i]=0;
    for(int i = 1; i <= q; ++i)
    {
        char ch = que[i].ch;
        int p = que[i].p;
        int t = que[i].t;
        if(ch == '!')
        {
            high[p] = t;
            play++;
        }
        else
        {
            int d = que[i].d;
            ds[p].pb({d, t});
        }
    }
    for(int i = 1; i <= n; ++i)
    {
        bool ok=false;
        sort(ds[i].begin(), ds[i].end());
        for(int j = 0; j < ds[i].size(); ++j)
        if((j==0||ds[i][j].fi!=ds[i][j-1].fi)&&(high[i]==0||ds[i][j].se<high[i]))
        {
            cnt[ds[i][j].fi]++;
            if(high[i]!=0)
                realcnt[ds[i][j].fi]++;
            ok=true;
        }
        if(!ok&&high[i]!=0)
        {
            cout<<-1<<' ';
            return;
        }
    }
    int res=-1;
    for(int i=1; i<=m; ++i)
        if(realcnt[i]==play)
        res=max(res, cnt[i]);
    cout<<res<<' ';
}
void loadinput()
{
    ds.assign(150001, vpa());
    cin >> sub >> t;
    while(t--)
    {
        cin >> n >> m >> q;
        for(int i = 1; i <= q; ++i)
        {
            cin >> que[i].ch;
            if(que[i].ch == '+')
                cin >> que[i].p >> que[i].d >> que[i].t;
            else
                cin >> que[i].p >> que[i].t;
        }
        solve();
    }
}
int main()
{
    faster;
    file();
    loadinput();
    return 0;
}


