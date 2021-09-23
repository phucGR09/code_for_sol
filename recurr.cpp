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
struct matrix
{
    int row, col;
    int c[50][50];
};
int k, n, d;
int b[51];
matrix f, a;
//.................................
void file()
{
    freopen("recurr.inp", "r", stdin);
    freopen("recurr.out", "w", stdout);
}
matrix mult(matrix ma, matrix mb)
{
    matrix res;
    res.row = ma.row;
    res.col = mb.col;
    for(int i = 0; i < res.row; ++i)
        for(int j = 0; j < res.col; ++j)
        {
            res.c[i][j] = 0;
            for(int e = 0; e < mb.row; ++e)
                res.c[i][j] = (res.c[i][j] + ma.c[i][e] * mb.c[e][j]) % 3;
        }
    return res;
}
matrix power(matrix ma, int x)
{
    if(x == 1)
        return ma;
    matrix res = power(ma, x / 2);
    if(x % 2 == 0)
        return mult(res, res);
    else
        return mult(mult(res, res), ma);
}
void solve()
{
    f.row = d, f.col = d;
    a.row = d, a.col = 1;
    for(int i = 0; i < d; ++i)
        f.c[0][i] = -1;
    f.c[0][d - 1] = 1;
    for(int i = 1; i < d; ++i)
        for(int j = 0; j < d; ++j)
            f.c[i][j] = ((i - j) == 1);
    matrix res = mult(power(f, n-1), a);
    for(int i=0; i<d; ++i)
        cout<<(res.c[i][0]+3)%3<<' ';
}
void loadinput()
{
    cin >> k;
    while(k--)
    {
        cin >> n >> d;
        for(int i = 1; i <= d; ++i)
            cin >> a.c[i - 1][0], a.c[i-1][0] = max(0, a.c[i-1][0]);
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


