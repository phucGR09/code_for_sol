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
const int nmax = 1e5 + 5;
const double eps = 1e-9;

//.................................
int n, m, a, b, c, d;
int mt[201][201];
int MAX = 0;
pa f[11][11][11][11];
int dx[5] = {0, -1, 0, 1, 0};
int dy[5] = {0, 0, 1, 0, -1};
int pre[5] = {0, 3, 4, 1, 2};
//.................................
void file()
{
    freopen("robot.inp", "r", stdin);
    freopen("robot.out", "w", stdout);
}
bool inside(pa x)
{
    if(x.fi < 1 || x.fi > n || x.se < 1 || x.se > m)
        return false;
    return true;
}
void solve()
{
    if(MAX == 0)
    {
        cout << 20 << '\n';
        cout << "UUUUUUUUUULLLLLLLLLL";
        return;
    }
    queue<pair<pa, pa> > q;
    q.push({{a, b}, {c, d}});
    f[a][b][c][d] = {1, 1};
    while(!q.empty())
    {
        pair<pa, pa> t = q.front();
        q.pop();
        pa x = t.fi, y = t.se;
        if(x.fi == 1 && x.se == 1 && y.fi == 1 && y.se == 1)
            break;
        for(int i = 1; i <= 4; ++i)
        {
            pa xnew = {x.fi + dx[i], x.se + dy[i]};
            pa ynew = {y.fi + dx[i], y.se + dy[i]};
            bool ok1 = inside(xnew);
            bool ok2 = inside(ynew);
            int go = 0; // x, y di chuyển
            if(!ok1 && !ok2)
                continue;
            if(!ok1 || mt[xnew.fi][xnew.se])
                xnew = x, go = 1; // x đứng yên, y di chuyển
            if(!ok2 || mt[ynew.fi][ynew.se])
                ynew = y, go = 2; // x di chuyển, y đứng yên
            if(f[xnew.fi][xnew.se][ynew.fi][ynew.se].fi != 0 || mt[xnew.fi][xnew.se] || mt[ynew.fi][ynew.se])
                continue;
            q.push({xnew, ynew});
            f[xnew.fi][xnew.se][ynew.fi][ynew.se] = {i, go};
        }
    }
    int x = 1, y = 1, k = 1, l = 1, cnt = 0;
    ve res;
    while(1)
    {
        if(x == a && y == b && k == c && l == d)
            break;
        res.push_back(f[x][y][k][l].fi);
        int i = pre[f[x][y][k][l].fi];
        int go = f[x][y][k][l].se;
        if(go != 1)
            x += dx[i], y += dy[i];
        if(go != 2)
            k += dx[i], l += dy[i];
        cnt++;
    }
    cout << res.size() << '\n';
    for(int i = res.size() - 1; i >= 0; --i)
    {
        if(res[i] == 1)
            cout << 'U';
        if(res[i] == 2)
            cout << 'R';
        if(res[i] == 3)
            cout << 'D';
        if(res[i] == 4)
            cout << 'L';
    }
}
void loadinput()
{
    cin >> n >> m >> a >> b >> c >> d;
    a++, b++, c++, d++;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            cin >> mt[i][j], MAX = max(MAX, mt[i][j]);
}
int main()
{
    faster;
    //file();
    loadinput();
    solve();
    return 0;
}
