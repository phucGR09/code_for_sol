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
const int mod = 111539786;
const int nmax = 1e5 + 5;
const double eps = 1e-9;

//.................................
int n, m;
int a[33][33];
int c[1025][1026];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
//.................................
void file()
{
    freopen("table3.inp", "r", stdin);
    freopen("table3.out", "w", stdout);
}
bool check(int x, int y)
{
    return (x >= 1 && x <= n && y >= 1 && y <= m);
}
ll power(int x, int y)
{
    if(y==0)
        return 1;
    ll res=power(x, y/2);
    if(y%2==0)
        return (res*res)%mod;
    return (res*(res*x)%mod)%mod;
}
void solve()
{
    int pt = 0, cnt = 0;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
        {
            pt++;
            for(int k = 0; k < 4; ++k)
            {
                int x = i + dx[k];
                int y = j + dy[k];
                if(check(x, y))
                    c[pt][(x - 1)*m + y] = 1;
            }
            c[pt][n * m + 1] = a[i][j];
        }
    for(int i = 1; i <= n * m; ++i)
    {
        int j = 1, ok=0;
        for(; j <= n * m; ++j)
            if(c[i][j])
            {
                ok=1;
                break;
            }
        if(!ok)
        {
            if(c[i][n*m+1]==0)
                cnt++;
            else
            {
                cout<<0;
                return;
            }
        }
        for(int x=i+1; x<=n*m; ++x)
        if(c[x][j]!=0)
        {
            int hs=(c[i][j]!=c[x][j]?1:2);
            for(int y=1; y<=n*m+1; ++y)
                c[x][y]=(c[x][y]+c[i][y]*hs)%3;
        }
    }
    cout<<power(3, cnt);
}
void loadinput()
{
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            cin >> a[i][j];
}
int main()
{
    faster;
    //file();
    loadinput();
    solve();
    return 0;
}


