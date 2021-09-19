#include<bits/stdc++.h>
using namespace std;

#define ll int64_t
#define fi first
#define se second
#define pb push_back
#define ve vector<ll>
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
struct Data
{
    int MIN, seMIN, MAX;
};
int n;
int a[nmax];
Data st[4*nmax];
//.................................
void file()
{
    freopen("triangle.inp", "r", stdin);
    freopen("triangle.out", "w", stdout);
}
Data get(Data L, Data R)
{
    Data res;
    res.MAX=max(L.MAX, R.MAX);
    if(L.MIN<R.MIN)
    {
        res.MIN=L.MIN;
        res.seMIN=min(L.seMIN, R.MIN);
    }
    else
    {
        res.MIN=R.MIN;
        res.seMIN=min(L.MIN, R.seMIN);
    }
    return res;
}
void build(int pos, int lo, int hi)
{
    if(lo==hi)
    {
        st[pos]={a[lo], INT_MAX, a[lo]};
        return;
    }
    int mid=(lo+hi)/2;
    build(pos*2, lo, mid);
    build(pos*2+1, mid+1, hi);
    st[pos]=get(st[pos*2], st[pos*2+1]);
}
Data get(int pos, int lo, int hi, int x, int y)
{
    if(x>y||lo>y||hi<x)
        return {INT_MAX, INT_MAX, 0};
    if(lo>=x&&hi<=y)
        return st[pos];
    int mid=(lo+hi)/2;
    Data L=get(pos*2, lo, mid, x, y);
    Data R=get(pos*2+1, mid+1, hi, x, y);
    return get(L, R);
}
bool check(int len)
{
    for(int i=len; i<=n; ++i)
    {
        Data d=get(1, 1, n, i-len+1, i);
        if(d.MAX<d.MIN+d.seMIN)
            return true;
    }
    return false;
}
void solve()
{
    build(1, 1, n);
    int l=3, r=n, res;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(check(mid))
        {
            l=mid+1;
            res=mid;
        }
        else
            r=mid-1;
    }
    cout<<res;
}
void loadinput()
{
    cin>>n;
    for(int i=1; i<=n; ++i)
        cin>>a[i];
}
int main()
{
    faster;
    //file();
    loadinput();
    solve();
    return 0;
}
