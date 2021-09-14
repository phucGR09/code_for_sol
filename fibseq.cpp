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
int n, p, q;
int a[nmax];
ll sum[nmax];
ll fibo[61];
ll res = 0;
//.................................
void file()
{
    freopen("fibseq.inp", "r", stdin);
    freopen("fibseq.out", "w", stdout);
}
void solve()
{
    fibo[0] = 0, fibo[1] = 1;
    for(int i = 2; i <= 60; ++i)
        fibo[i] = fibo[i - 1] + fibo[i - 2];
    for(int i = 1; i <= n; ++i)
        sum[i] = sum[i - 1] + a[i];
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 0; j <= 60; ++j)
            if(j != 1 )
            {
                if(fibo[j]>sum[i])
                    break;
                if(j == 0 && a[i] > 0)
                    continue;
                ll k = sum[i] - fibo[j];
                int x = lower_bound(sum, sum + n + 1, k) - sum;
                int y = upper_bound(sum, sum + n + 1, k) - sum;
                y = min(y, i);
                if(sum[x] != k)
                    continue;
                int t = y - x - 1, len = i - y + 1;
                if(len > q)
                    continue;
                t = min(t, q - len);
                if(len >= p)
                    res += t + 1;
                else
                    res += max(0, t - (p - len) + 1);
            }
    }
    cout << res;
}
void loadinput()
{
    cin >> n >> p >> q;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
}
int main()
{
    faster;
    //file();
    loadinput();
    solve();
    return 0;
}
