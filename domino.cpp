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
int n, m, k;
int a[35][35];
int space[35][35];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int E[1030][1030];
int level[1030];
vve dsk;
//.................................
void file()
{
    freopen("domino.inp", "r", stdin);
    freopen("domino.out", "w", stdout);
}
bool insquare(int i, int j, int x, int y, int xx, int yy)
{
    if(i < xx || i > x || j < yy || j > y)
        return false;
    return true;
}
bool inside(int i, int j)
{
    if(i < 1 || i > n || j < 1 || j > m)
        return false;
    return true;
}
int bfs(int u, int v)
{
    //cout<<u<<' '<<v<<'\n';
    for(int i = 0; i <= n * m + 1; ++i)
        level[i] = 0;
    level[u] = 1;
    queue<int>q;
    q.push(u);
    while(!q.empty())
    {
        int x = q.front();
        q.pop();
        for(int i = 0; i < dsk[x].size(); ++i)
        {
            int y = dsk[x][i];
            if(!level[y] && E[x][y])
            {
                level[y] = level[x] + 1;
                q.push(y);
            }
        }
    }
    return level[v];
}
ll dfs(int u, ll cost)
{
    if(u == n * m + 1)
        return cost;
    for(int i = 0; i < dsk[u].size(); ++i)
    {
        int v = dsk[u][i];
        if(E[u][v] && level[v] == level[u] + 1)
        {
            ll c = dfs(v, min((ll)E[u][v], cost));
            if(c)
            {
                E[u][v] -= c;
                E[v][u] += c;
                return c;
            }
        }
    }
    return 0;
}
bool can_put(int x, int y, int len)
{
    for(int i = 0; i <= n * m + 1; ++i)
        dsk[i].clear();
    int xx = x - len + 1, yy = y - len + 1;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            if(!a[i][j] && ((i % 2) == (j % 2)) && !insquare(i, j, x, y, xx, yy))
            {
                int u = m * (i - 1) + j;
                for(int t = 0; t < 4; ++t)
                {
                    int ii = i + dx[t];
                    int jj = j + dy[t];
                    if(!a[ii][jj] && inside(ii, jj) && !insquare(ii, jj, x, y, xx, yy))
                    {
                        int v = m * (ii - 1) + jj;
                        dsk[u].pb(v);
                        dsk[v].pb(u);
                        E[u][v] = 1;
                    }
                }
            }
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            if(!a[i][j] && !insquare(i, j, x, y, xx, yy))
            {
                int u = m * (i - 1) + j;
                if(i % 2 == j % 2)
                {
                    dsk[0].pb(u);
                    dsk[u].pb(0);
                    E[0][u] = 1;
                }
                else
                {
                    dsk[n * m + 1].pb(u);
                    dsk[u].pb(n * m + 1);
                    E[u][n * m + 1] = 1;
                }
            }
    ll res = 0;
    while( bfs(0, n * m + 1))
    {
        ll cost;
        while(cost = dfs(0, INF))
            res += cost;
        if(res >= k)
            return true;
    }
    return false;
}
bool check(int len)
{
    for(int i = len; i <= n; ++i)
    {
        for(int j = len; j <= m; ++j)
        {
            int sum = space[i][j] - space[i - len][j] - space[i][j - len] + space[i - len][j - len];
            if(sum == 0 && can_put(i, j, len))
                return true;
        }
    }
    return false;
}
void solve()
{
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            space[i][j] = space[i - 1][j] + space[i][j - 1] - space[i - 1][j - 1] + a[i][j];
    int l = 1, r = min(n, m), len = 1;
    while(l <= r)
    {
        int mid = (l + r) / 2;
        if(check(mid))
            len = mid, l = mid + 1;
        else
            r = mid - 1;
    }
    cout << len << '\n';
}
void loadinput()
{
    cin >> n >> m >> k;
    dsk.assign(n * m + 3, ve());
    for(int i = 1; i <= n; ++i)
    {
        string s;
        cin >> s;
        for(int j = 1; j <= m; ++j)
            a[i][j] = (s[j - 1] == '#');
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


