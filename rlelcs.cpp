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
string xE, yE;
string x = "", y = "";
vector<ll> numx, numy;
ll f[1001][1001];
int pos[2][1001];
int mem[26];
//.................................
void file()
{
    freopen("rlelcs.inp", "r", stdin);
    freopen("rlelcs.out", "w", stdout);
}
void query1()
{
    for(int i = 1; i < x.size(); ++i)
    {
        pos[0][i] = mem[x[i] - 'a'];
        mem[x[i] - 'a'] = i;
    }
    for(int i = 0; i < 26; ++i)
        mem[i] = 0;
    for(int i = 1; i < y.size(); ++i)
    {
        pos[1][i] = mem[y[i] - 'a'];
        mem[y[i] - 'a'] = i;
    }
    pos[0][0] = -1;
    pos[1][0] = -1;
    for(int i = 1; i < x.size(); ++i)
        for(int j = 1; j < y.size(); ++j)
        {
            if(x[i] == y[j])
            {
                f[i][j] = max(f[i][j], f[i - 1][j - 1] + min(numx[i], numy[j]));
                ll a = numx[i], b = numy[j];
                int ii = i, jj = j;
                while(pos[0][ii] > 0)
                {
                    ii = pos[0][ii];
                    a += numx[ii];
                    if(jj >= 0)
                        f[i][j] = max(f[i][j], f[ii - 1][jj - (jj != 0)]  + min(a, b));
                    while(pos[1][jj] >= 0 && b < a)
                    {
                        jj = pos[1][jj];
                        b += numy[jj];
                        f[i][j] = max(f[i][j], f[ii - 1][jj - (jj != 0)] + min(a, b));
                    }
                }
                a = numx[i], b = numy[j];
                ii = i, jj = j;
                while(pos[1][jj] > 0 )
                {
                    jj = pos[1][jj];
                    b += numy[jj];
                    if(ii >= 0)
                        f[i][j] = max(f[i][j], f[ii - (ii != 0)][jj - 1] + min(a, b));
                    while(pos[0][ii] >= 0 && a < b)
                    {
                        ii = pos[0][ii];
                        a += numx[ii];
                        f[i][j] = max(f[i][j], f[ii - (ii != 0)][jj - 1] + min(a, b));
                    }
                }
            }
            f[i][j] = max(f[i][j], f[i - 1][j]);
            f[i][j] = max(f[i][j], f[i][j - 1]);
            f[i][j] = max(f[i][j], f[i - 1][j - 1]);
        }
    ll res = 0;
    for(int i = 1; i < x.size(); ++i)
        for(int j = 1; j < y.size(); ++j)
            res = max(res, f[i][j]);
    cout << res << '\n';
}
void query2()
{
    ll res = 0;
    for(int i = 1; i < x.size(); ++i)
        for(int j = 1; j < y.size(); ++j)
            if(x[i] == y[j])
            {
                ll len = min(numx[i], numy[j]);
                for(int k = i - 1, l = j - 1; k > 0 && l > 0; --k, --l)
                {
                    if(x[k] != y[l])
                        break;
                    else
                    {
                        if(numx[k] != numy[l])
                        {
                            len += min(numx[k], numy[l]);
                            break;
                        }
                        len += numx[k];
                    }
                }
                res = max(res, len);
            }
    cout << res;
}
void solve()
{
    x += ' ';
    y += ' ';
    numx.push_back(0);
    numy.push_back(0);
    int i = 0;
    while(i < xE.size())
    {
        x += xE[i];
        ll s = 0;
        i++;
        while(i < xE.size() && xE[i] >= '0'&xE[i] <= '9')
            s = s * 10 + xE[i] - '0', i++;
        numx.push_back(s);
    }
    i = 0;
    while(i < yE.size())
    {
        y += yE[i];
        ll s = 0;
        i++;
        while(i < yE.size() && yE[i] >= '0' && yE[i] <= '9')
            s = s * 10 + yE[i] - '0', i++;
        numy.push_back(s);
    }
    query1();
    query2();
}
void loadinput()
{
    cin >> xE >> yE;
}
int main()
{
    faster;
    //file();
    loadinput();
    solve();
    return 0;
}

