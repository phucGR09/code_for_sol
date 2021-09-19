```#include < bits / stdc++.h >
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
struct Data
{
    int l, r, c;
};
int n, m;
ll a[2 * nmax];
ll st[8 * nmax];
int cs[17];
vector<Data> que;
vve open, close;
//.................................
void file()
{
    freopen("gcdseq.inp", "r", stdin);
    freopen("gcdseq.out", "w", stdout);
}
void build(int pos, int lo, int hi)
{
    if(lo == hi)
    {
        st[pos] = a[lo];
        return;
    }
    int mid = (lo + hi) / 2;
    build(pos * 2, lo, mid);
    build(pos * 2 + 1, mid + 1, hi);
    st[pos] = __gcd(st[pos * 2], st[pos * 2 + 1]);
}
ll get(int pos, int lo, int hi, int x, int y)
{
    if(x > y || lo > y || hi < x)
        return -1;
    if(lo >= x && hi <= y)
        return st[pos];
    int mid = (lo + hi) / 2;
    int L = get(pos * 2, lo, mid, x, y);
    int R = get(pos * 2 + 1, mid + 1, hi, x, y);
    if(L == -1)
        return R;
    else if(R == -1)
        return L;
    else
        return __gcd(L, R);
}
void solve()
{
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 0; j < open[i].size(); ++j)
            cs[open[i][j]]++;
        int p = -1;
        for(int j = 1; j <= 16; ++j)
            if(cs[j])
                p = (p == -1 ? j : (p * j) / __gcd(p, j));
        a[i] = p;
        for(int j = 0; j < close[i].size(); ++j)
            cs[close[i][j]]--;
    }
    build(1, 1, n);
    for(int i = 0; i < que.size(); ++i)
    {
        int l = que[i].l, r = que[i].r, c = que[i].c;
        if(get(1, 1, n, l, r) != c)
        {
            cout << -1;
            return;
        }
    }
    for(int i = 1; i <= n; ++i)
        cout << max((ll)1, a[i]) << ' ';
}
void loadinput()
{
    cin >> n >> m;
    open.assign(n + 1, ve());
    close.assign(n + 1, ve());
    for(int i = 1; i <= m; ++i)
    {
        int l, r, c;
        cin >> l >> r >> c;
        que.pb({l, r, c});
        open[l].pb(c);
        close[r].pb(c);
    }
}
int main()
{
    faster;
    //file();
    loadinput();
    solve();
    return 0;
}```

