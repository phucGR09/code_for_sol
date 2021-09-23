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
int n, m;
vector<string> a;
int cntA[31], cntB[31];
//.................................
void file()
{
    freopen("dabstr.inp", "r", stdin);
    freopen("dabstr.out", "w", stdout);
}
void solve()
{
    m=a[0].size();
    int res=INT_MAX;
    for(int i=0; i<(1<<n); ++i)
    {
        int teamA=0, teamB=0, cnt=0;
        for(int j=0; j<m; ++j)
            cntA[j]=0, cntB[j]=0;
        for(int j=0; j<n; ++j)
        {
            if((i>>j)&1)
            {
                teamA++;
                for(int k=0; k<m; ++k)
                    cntA[k]+=a[j][k]-'0';
            }
            else
            {
                teamB++;
                for(int k=0; k<m; ++k)
                    cntB[k]+=a[j][k]-'0';
            }
        }
        for(int j=0; j<m; ++j)
            cnt+=min(cntA[j], teamA-cntA[j])+min(cntB[j], teamB-cntB[j]);
        res=min(res, cnt);
    }
    cout<<res;
}
void loadinput()
{
    cin>>n;
    for(int i=0; i<n; ++i)
    {
        string s;
        cin>>s;
        a.pb(s);
    }
}
int main()
{
    faster;
    file();
    loadinput();
    solve();
    return 0;
}

