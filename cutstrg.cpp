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
const int mod = 123213311;
const int nmax = 2e5 + 1;
const double eps = 1e-9;

//.................................
int k;
string a, b;
ll f[2005][2005];
ll res = 0;
//.................................
void file()
{
    freopen("cutstrg.inp", "r", stdin);
    freopen("cutstrg.out", "w", stdout);
}
bool check(pa x, pa y, pa z)
{
    int i = x.se;
    if(f[i][x.fi] < x.se) return false;
    i += y.se;
    if(f[i][y.fi] < y.se) return false;
    i += z.se;
    if(f[i][z.fi] < z.se) return false;
    return true;
}
void solve()
{
    a = ' ' + a;
    b = ' ' + b;
    for(int i = 1; i < a.size(); ++i)
        for(int j = 1; j < b.size(); ++j)
            if((k==0?a[i]==b[j]:1)&&abs(a[i] - b[j]) <= k)
                f[i][j] = f[i - 1][j - 1] + 1;
    for(int i = 1; i < b.size() - 2; ++i)
        for(int j = i + 1; j < b.size() - 1; ++j)
        {
            bool ok = false;
            pa x = {i, i}, y = {j, j - i}, z = {b.size() - 1, b.size() - j - 1};
            //cout<<x.fi<<' '<<x.se<<' '<<y.fi<<' '<<y.se<<' '<<z.fi<<' '<<z.se<<'\n';
            if(check(x, y, z)) ok = true;
            if(check(x, z, y)) ok = true;
            if(check(y, x, z)) ok = true;
            if(check(y, z, x)) ok = true;
            if(check(z, x, y)) ok = true;
            if(check(z, y, x)) ok = true;
            if(ok)
                res++;
        }
    cout << res;
}
void loadinput()
{
    cin >> k;
    cin >> a >> b;
}
int main()
{
    faster;
    //file();
    loadinput();
    solve();
    return 0;
}

