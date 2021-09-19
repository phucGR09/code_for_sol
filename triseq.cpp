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
ll n, t;
int arr[19];
ll f[19][19][19][19];
ve val;
ll vt = 0;
ll tt_a = 0;
//.................................

void file()
{
    freopen("triseq.inp", "r", stdin);
    freopen("triseq.out", "w", stdout);
}
ll query(int i, int min1, ll min2, ll max_a)
{
    if(i > n)
        return 1;
    ll &res = f[i][min1][min2][max_a];
    if(res != -1)
        return res;
    res = 0;
    for(int j = 1; j <= n; ++j)
    {
        int a = min1, b = min2, c = max_a;
        if(a > j)
        {
            b = a;
            a = j;
        }
        else if(b > j) b = j;
        if(c < j) c = j;
        if(a + b > c)
            res += query(i + 1, a, b, c);
    }
    return res;
}
void positive(int i, int min1, int min2, int max_a)
{
    if(i > n)
        return;
    for(int j = 1; j <= n; ++j)
    {
        int a = min1, b = min2, c = max_a;
        if(a > j)
        {
            b = a;
            a = j;
        }
        else if(b > j) b = j;
        if(c < j) c = j;
        if(a + b > c)
        {
            ll next = query(i + 1, a, b, c);
            if(vt + next >= t)
            {
                val.push_back(j);
                positive(i + 1, a, b, c);
                return;
            }
            vt += next;
        }
    }
}
void vt_arr(int i, int min1, int min2, int max_a)
{
    if(i > n)
        return;
    for(int j = 1; j < arr[i]; ++j)
    {
        int a = min1, b = min2, c = max_a;
        if(a > j)
        {
            b = a;
            a = j;
        }
        else if(b > j) b = j;
        if(c < j) c = j;
        if(a + b > c)
            tt_a += query(i + 1, a, b, c);
    }
    int a = min1, b = min2, c = max_a;
    if(a > arr[i])
    {
        b = a;
        a = arr[i];
    }
    else if(b > arr[i])
        b = arr[i];
    if(c < arr[i])
        c = arr[i];
    vt_arr(i + 1, a, b, c);
}
void solve()
{
    makefill(f, -1);
    cout << query(1, n + 1, n + 1, 0) << '\n';
    positive(1, n + 1, n + 1, 0);
    for(int i = 0; i < val.size(); ++i)
        cout << val[i] << ' ';
    cout << '\n';
    vt_arr(1, n + 1, n + 1, 0);
    cout << tt_a + 1;

}
void loadinput()
{
    cin >> n >> t;
    for(int i = 1; i <= n; ++i)
        cin >> arr[i];
}
int main()
{
    faster;
    //file();
    loadinput();
    solve();
    return 0;
}
