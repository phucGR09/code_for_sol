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
const ll mod = 1e9 + 7;
const int nmax = 1e6 + 5;
const double eps = 1e-9;

//.................................
int q;
pair<char, int> query[nmax];
int valreal[nmax];
int st[4 * nmax];
//.................................
void file()
{
    freopen("medquery.inp", "r", stdin);
    freopen("medquery.out", "w", stdout);
}
void update(int pos, int lo, int hi, int x, int val)
{
    if(lo == hi)
    {
        st[pos] += val;
        return;
    }
    int mid = (lo + hi) / 2;
    if(x <= mid)
        update(pos * 2, lo, mid, x, val);
    else
        update(pos * 2 + 1, mid + 1, hi, x, val);
    st[pos] = st[pos * 2] + st[pos * 2 + 1];
}
int get(int pos, int lo, int hi, int k)
{
    if(lo == hi)
        return lo;
    int mid = (lo + hi) / 2;
    if(st[pos * 2] < k)
        return get(pos * 2 + 1, mid + 1, hi, k - st[pos * 2]);
    return get(pos * 2, lo, mid, k);
}
void solve()
{
    vpa ds;
    for(int i = 1; i <= q; ++i)
        cin >> query[i].fi >> query[i].se, ds.pb({query[i].se, i});
    sort(ds.begin(), ds.end());
    query[ds[0].se].se = 1;
    valreal[1] = ds[0].fi;
    for(int i = 1; i < ds.size(); ++i)
    {
        query[ds[i].se].se = query[ds[i - 1].se].se + (ds[i].fi != ds[i - 1].fi);
        valreal[query[ds[i].se].se] = ds[i].fi;
    }
    int len = 0;
    for(int i = 1; i <= q; ++i)
    {
        if(query[i].fi == '-')
        {
            len--;
            update(1, 1, q, query[i].se, -1);
        }
        else
        {
            len++;
            update(1, 1, q, query[i].se, 1);
        }
        int it = get(1, 1, q, (len + 1) / 2);
        cout << valreal[it] << '\n';
    }
}
void loadinput()
{
    cin >> q;
}
int main()
{
    faster;
    //file();
    loadinput();
    solve();
    return 0;
}


