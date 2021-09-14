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
ll n, m;
string t, p;
ve numt;
ll f[31][nmax];
ll c[31][nmax];
//.................................
void file()
{
    freopen("password03.inp", "r", stdin);
    freopen("password03.out", "w", stdout);
}
string getstr(string s, ve &num)
{
    string res = " ";
    num.clear();
    num.push_back(0);
    int i = 0;
    while(i < s.size())
    {
        res += s[i];
        ll k = 0;
        i++;
        while(i < s.size() && s[i] >= '0'&s[i] <= '9')
            k = (k * 10 + s[i] - '0') % mod, i++;
        num.push_back(k);
    }
    return res;
}

void solve()
{
    t = getstr(t, numt);
    p = ' ' + p;
    for(int i = 0; i < nmax; ++i)
        c[0][i] = 1;
    for(int j = 1; j < nmax; ++j)
        for(int i = 1; i <= min(30, j); ++i)
            c[i][j] = (c[i][j - 1] + c[i - 1][j - 1]) % mod;
    for(int i = 0; i < t.size(); ++i)
        f[0][i] = 1;
    for(int i = 1; i < p.size(); ++i)
        for(int j = 1; j < t.size(); ++j)
        {
            f[i][j] = f[i][j - 1];
            if(p[i] == t[j])
            {
                int k = i;
                ll cnt = 1;
                while(cnt <= numt[j] && p[i] == p[k])
                    f[i][j] = (f[i][j] + (f[k-1][j-1]*c[cnt][numt[j]])%mod)%mod, k--, cnt++;
            }
        }
    cout << f[p.size() - 1][t.size() - 1];
}
void loadinput()
{
    cin >> n >> m;
    cin >> t >> p;
}
int main()
{
    faster;
    //file();
    loadinput();
    solve();
    return 0;
}

