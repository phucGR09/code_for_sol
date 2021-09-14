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
const int mod = 111539786;
const int nmax = 2e5 + 1;
const double eps = 1e-9;

//.................................
string x;
ve numx;
vve pos;
int conti[1001][27];
ll f[1001];

//.................................
void file()
{
    freopen("d13rlesubstr.inp", "r", stdin);
    freopen("d13rlesubstr.out", "w", stdout);
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
            k = (k * 10 + s[i] - '0')%mod, i++;
        num.push_back(k);
    }
    return res;
}

void solve()
{
    x = getstr(x, numx);
    pos.assign(27, ve());
    for(int i = 0; i < x.size(); ++i)
        f[i] = 0;
    for(int i = 0; i < x.size(); ++i)
        for(int j = 1; j <= 26; ++j)
            conti[i][j] = 0;
    for(int i = x.size() - 1; i > 0; --i)
        pos[x[i] - 'a' + 1].push_back(i);
    for(int i = 0; i < x.size(); ++i)
    {
        if(i != 0)
            pos[x[i] - 'a' + 1].pop_back();
        for(int j = 1; j <= 26; ++j)
            if(!pos[j].empty())
                conti[i][j] = pos[j].back();
    }
    f[0] = 1;
    numx[0] = 1;
    for(int i = 0; i < x.size(); ++i)
    {
        for(int j = 1; j <= 26; ++j)
            if(conti[i][j])
            {
                int it = conti[i][j];
                f[it] = (f[it] + (f[i] * (x[i] != x[it] ? numx[i] : 1)) % mod) % mod;
            }
    }
    ll res = 0;
    for(int i = 1; i < x.size(); ++i)
        res = (res + (f[i] * numx[i]) % mod) % mod;
    cout << res << '\n';
    for(int i = 1; i <= 26; ++i)
        pos[i].clear();
}
void loadinput()
{
    ll t;
    cin >> t;
    while(t--)
    {
        cin >> x;
        solve();
    }
}
int main()
{
    faster;
    //file();
    loadinput();
    return 0;
}
