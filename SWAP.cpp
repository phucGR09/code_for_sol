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
int t;
string s;
vve ch;
int cnt[27];
pa st[120];
//.................................
void file()
{
    freopen("SWAP.inp", "r", stdin);
    freopen("SWAP.out", "w", stdout);
}
void build(int pos, int lo, int hi)
{
    if(lo==hi)
    {
        st[pos]={lo, cnt[lo]};
        return;
    }
    int mid=(lo+hi)/2;
    build(pos*2, lo, mid);
    build(pos*2+1, mid+1, hi);
    if(st[pos*2].se>st[pos*2+1].se)
        st[pos]=st[pos*2];
    else
        st[pos]=st[pos*2+1];
}
pa get(int pos, int lo, int hi, int x, int y)
{
    if(x>y||lo>y||hi<x)
    return {0, 0};
    if(lo>=x&&hi<=y)
        return st[pos];
    int mid=(lo+hi)/2;
    pa L=get(pos*2, lo, mid, x, y);
    pa R=get(pos*2+1, mid+1, hi, x, y);
    if(L.se>R.se)
        return L;
    else
        return R;
}
void update(int pos, int lo, int hi, int x)
{
    if(lo==hi)
    {
        st[pos].se--;
        return;
    }
    int mid=(lo+hi)/2;
    if(x<=mid)
        update(pos*2, lo, mid, x);
    else
        update(pos*2+1, mid+1, hi, x);
    if(st[pos*2].se>st[pos*2+1].se)
        st[pos]=st[pos*2];
    else
        st[pos]=st[pos*2+1];
}
void check()
{
    int pos[3], it=0;
    for(int i=1; i<=26; ++i)
        if(ch[i].size()>0)
        {
            pos[it]=ch[i].back();
            update(1, 1, 26, i);
            ch[i].pop_back();
            it++;
        }
    swap(s[pos[0]], s[pos[1]]);
    swap(s[pos[1]], s[pos[2]]);
}
void solve()
{
    ch.assign(27, ve());
    for(int i=1; i<=26; ++i)
        cnt[i]=0;
    for(int i=0; i<s.size(); ++i)
        {
            ch[s[i]-'a'+1].pb(i);
            cnt[s[i]-'a'+1]++;
        }
    for(int i=1; i<=26; ++i)
        if(cnt[i]>s.size()/2)
    {
        cout<<"Impossible"<<'\n';
        return;
    }
    build(1, 1, 26);
    int d=s.size();
    while(d>0)
    {
        if(d==3)
        {
            check();
            break;
        }
        int k=st[1].fi;
        pa it=get(1, 1, 26, 1, k-1);
        if(!it.se)
            it=get(1, 1, 26, k+1, 26);
        int x=ch[k].back();
        int y=ch[it.fi].back();
        ch[k].pop_back();
        ch[it.fi].pop_back();
        swap(s[x], s[y]);
        update(1, 1, 26, k);
        update(1, 1, 26, it.fi);
        d-=2;
    }
    cout<<s<<'\n';
}
void loadinput()
{
    cin>>t;
    while(t--)
    {
        cin>>s;
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


