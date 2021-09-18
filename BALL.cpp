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
ll n, a, b, c, w;
ll f1[11][11], f2[11][11], f3[11][11], f[11][11][11];
ll dp[(1<<10)][(1<<10)];
//.................................
void file()
{
    freopen("BALL.inp", "r", stdin);
    freopen("BALL.out", "w", stdout);
}
void solve()
{
    for(int red = 1; red < (1 << n); ++red)
        for(int yellow = 1; yellow < (1 << n); ++yellow)
        {
            int x = 0, y=0;
            for(int i = 0; i < n; ++i)
                x += (((red >> i) & 1)==1);
            for(int i = 0; i < n; ++i)
                y += (((yellow >> i) & 1)==1);
            if(x!=y)
                continue;
            for(int i = 0; i < n; ++i)
                if((red >> i) & 1)
                    for(int j = 0; j < n; ++j)
                        if((yellow >> j) & 1)
                        dp[red][yellow]=max(dp[red][yellow], dp[red^(1<<i)][yellow^(1<<j)]
                                                                             +a*f1[x][i+1]
                                                                             +b*f2[x][j+1]
                                                                             +c*f3[i+1][j+1]
                                                                             +w*f[x][i+1][j+1]);
        }
    cout<<dp[(1<<n)-1][(1<<n)-1];
}
void loadinput()
{
    cin >> n >> a >> b >> c >> w;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            cin >> f1[i][j];
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            cin >> f2[i][j];
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            cin >> f3[i][j];
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            for(int k = 1; k <= n; ++k)
                cin >> f[i][j][k];
}
int main()
{
    faster;
    //file();
    loadinput();
    solve();
    return 0;
}

