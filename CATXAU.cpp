#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fi first
#define se second
#define pb push_back
#define mp makepair
#define ve vector<ll>
#define vve vector<ve>
#define pa pair<ll, ll>
#define vpa vector<pa>
#define makefill(f, c) memset(f, c, sizeof(f))
#define faster ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

const ll INF = 1e18;
const ll mod = 1e9 + 7;
const ll nmax = 1e5 + 1;
const double eps = 1e-9;

string a, b;
vpa ds;
ve cost;
ll f[3*nmax];
bool cmp(pa x, pa y)
{
    if(cost[x.fi] < cost[y.fi])
        return true;
    else if(cost[x.fi] == cost[y.fi])
    {
        if(cost[x.se] < cost[y.se])
            return true;
    }
    return false;
}
bool kt(pa x, pa y)
{
    if(cost[x.fi] != cost[y.fi])
        return true;
    else if(cost[x.se] != cost[y.se])
        return true;
    return false;
}
bool find_in_b(ll i, ll j)
{
    ll sz = j - i + 1;
    string x = "";
    for(ll u = i; u <= j; ++u)
        x += a[u];
    ll l = 0, r = ds.size() - 1;
    while(l <= r)
    {
        ll mid = (l + r) / 2;
        string y = "";
        for(ll u = ds[mid].fi; u < min(ds[mid].fi + sz, (ll)b.size() - 1); ++u)
            y += b[u];
        if(x == y)
            return true;
        else if(x < y)
            r = mid - 1;
        else
            l = mid + 1;
    }
    return false;
}
int main()
{
    //freopen(".inp", "r", stdin);
    //freopen(".out", "w", stdout);
    faster;
    cin >> a >> b;
    b += '$';
    a = ' ' + a;
    cost.assign(b.size(), 0);
    // tinh size
    ll k = 0;
    while((1 << k) < b.size())
        k++;
    // gan cac gia tri dau tien cho cost
    for(ll i = 0; i < b.size(); ++i)
        ds.pb({(int)b[i], i});
    sort(ds.begin(), ds.end());
    cost[ds[0].se] = 0;
    for(ll i = 1; i < ds.size(); ++i)
    {
        if(ds[i].fi == ds[i - 1].fi)
            cost[ds[i].se] = cost[ds[i - 1].se];
        else
            cost[ds[i].se] = cost[ds[i - 1].se] + 1;
    }
    // suffix array
    for(ll i = 1; i <= k; ++i)
    {
        ds.clear();
        ll d = (1 << (i - 1));
        for(ll j = 0; j < b.size(); ++j)
            ds.pb({j, (j + d) % b.size()});
        sort(ds.begin(), ds.end(), cmp);
        ve tam;
        tam.assign(b.size(), 0);
        for(ll j = 1; j < ds.size(); ++j)
        {
            tam[ds[j].fi] = tam[ds[j - 1].fi];
            if(kt(ds[j], ds[j - 1]))
                tam[ds[j].fi]++;
        }
        cost = tam;
    }
    f[0] = 1;
    ll pos = 1;
    for(ll i = 1; i < a.size(); ++i)
    {
        while(pos <= i && !find_in_b(pos, i))
            pos++;
        if(pos <= i)
        {
            if(pos == 1)
                f[i] = f[i - 1];
            else
                f[i] = (f[i - 1] - f[pos - 2] + mod * mod) % mod;
        }
        if(i != a.size() - 1)
            f[i] = (f[i] + f[i - 1]) % mod;
    }
    cout << f[a.size() - 1];
}
