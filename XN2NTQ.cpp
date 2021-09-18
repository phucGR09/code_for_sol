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
const int nmax = 1e6 + 1;
const double eps = 1e-9;

//.................................
int n;
pa a[nmax + 4];
int num[nmax + 4];
int mem[2 * nmax];
int E[1005][1005];
int dad[1005];
int mau[1005];
int trace[1005];
int pos[1005];
ve nt;
//.................................
void file()
{
    freopen("XN2NTQ.inp", "r", stdin);
    freopen("XN2NTQ.out", "w", stdout);
}
void sub1_3()
{
    cout << n / 2 << '\n';
    int i = n;
    while(i > 1)
    {
        ll k = i * 2;
        ll x = lower_bound(nt.begin(), nt.end(), k) - nt.begin();
        x--;
        ll l = nt[x] - i, r = i;
        i = l - 1;
        while(l < r)
        {
            cout << num[l] << ' ' << num[r] << '\n';
            l++, r--;
        }
    }
}
void bfs(int u, int v)
{
    queue<int> q;
    q.push(u);
    mau[u] = 1;
    while(!q.empty())
    {
        int top = q.front();
        q.pop();
        if(top==v)
            return;
        for(int i = 0; i <= n + 1; ++i)
            if(i != top && E[top][i] && !mau[i])
            {
                mau[i] = 1;
                dad[i] = top;
                q.push(i);
            }
    }
}
void way(int u, int v)
{
    while(v != u)
    {
        E[dad[v]][v]--;
        E[v][dad[v]]++;
        trace[v] = dad[v];
        v = dad[v];
    }
}
void sub2()
{
    for(int i = 1; i <= n; ++i)
        if(a[i].fi % 2 == 1)
            for(int j = 1; j <= n; ++j)
                if(i != j && !mem[a[i].fi + a[j].fi])
                    E[i][j] = 1;
    for(int i = 1; i <= n; ++i)
        if(a[i].fi % 2 == 1)
            E[0][i] = 1;
    for(int i = 1; i <= n; ++i)
        if(a[i].fi % 2 == 0)
            E[i][n + 1] = 1;
    for(int i = 0; i <= n + 1; ++i)
        trace[i] = i;

    while(1)
    {
        for(int i = 0; i <= n + 1; ++i)
            dad[i] = i, mau[i] = 0;
        bfs(0, n+1);
        if(!mau[n + 1])
            break;
        else
            way(0, n + 1);
    }
    vpa ds;
    ve ds1;
    for(int i = 1; i <= n; ++i)
        mau[i] = 0;
    for(int i = 1; i <= n; ++i)
        if(a[i].fi % 2 == 0 && trace[i] != i)
        {
            ds.pb({a[trace[i]].se, a[i].se});
            if(a[trace[i]].fi == 1)
                mau[trace[i]] = 1;
        }

    for(int i = 1; i <= n; ++i)
        if(a[i].fi == 1 && !mau[i])
            ds1.pb(a[i].se);
    cout << ds.size() + ds1.size() / 2 << '\n';
    for(int i = 1; i < ds1.size();  i += 2)
        cout << ds1[i - 1] << ' ' << ds1[i] << '\n';
    for(int i = 0; i < ds.size(); ++i)
    {
        cout << ds[i].fi << ' ' << ds[i].se << '\n';
    }
}
void solve()
{
    for(ll i = 2; i < 2000000; ++i)
        if(!mem[i])
        {
            nt.push_back(i);
            ll s = i*i;
            while(s < 2000000)
            {
                mem[s] = 1;
                s += i;
            }
        }
    bool ok = true;
    sort(a + 1, a + n + 1, greater<pa>());
    for(int i = 1; i < n; ++i)
        if(a[i].fi - a[i + 1].fi != 1)
            ok = false;
    if(ok)
        sub1_3();
    else
        sub2();
}
void loadinput()
{
    cin >> n;
    for(int i = 1; i <= n; ++i)
    {
        cin >> a[i].fi;
        a[i].se = i;
        num[a[i].fi] = i;
    }
}
int main()
{
    //file();
    faster;
    loadinput();
    solve();
    return 0;
}

