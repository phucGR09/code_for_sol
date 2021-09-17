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
int v, n, m;
ll p[21];
ll dist[21][33000];
pa hv[6];
//.................................
void file()
{
    freopen("POUR.inp", "r", stdin);
    freopen("POUR.out", "w", stdout);
}

void dijkstra(int x, int y)
{
    for(int i=0; i<=n; ++i)
        for(int j=0; j<=v; ++j)
        dist[i][j]=INF;
    dist[x][y]=0;
    priority_queue<pair<ll, pa>, vector<pair<ll, pa> >, greater<pair<ll, pa> > > q;
    q.push({0, {x, y}});
    while(!q.empty())
    {
        pair<ll, pa> top=q.top();
        q.pop();
        int bottle[3], l=top.se.fi, w=top.se.se;
        if(dist[l][w]!=top.fi)
            continue;
        bottle[0]=p[l];
        bottle[1]=w;
        bottle[2]=v-bottle[0]-bottle[1];
        if(bottle[0]==m||bottle[1]==m||bottle[2]==m)
        {
            cout<<top.fi;
            exit(0);
        }
        for(int i=0; i<6; ++i)
        {
            int a=bottle[hv[i].fi];
            int b=bottle[hv[i].se];
            for(int j=0; p[j]<a&&j<=n; ++j)
            {
                int c=a-p[j];
                if(dist[j][b+c]>dist[l][w]+1)
                {
                    dist[j][b+c]=dist[l][w]+1;
                    q.push({dist[j][b+c], {j, b+c}});
                }
            }
            for(int j=n; p[j]>b&&j>=0; --j)
            {
                int c=p[j]-b;
                if(c>a)
                    continue;
                if(dist[j][a-c]>dist[l][w]+1)
                {
                    dist[j][a-c]=dist[l][w]+1;
                    q.push({dist[j][a-c], {j, a-c}});
                }
            }
        }
    }
}
void solve()
{
    hv[0]={0, 1};
    hv[1]={0, 2};
    hv[2]={1, 0};
    hv[3]={1, 2};
    hv[4]={2, 0};
    hv[5]={2, 1};

    dijkstra(0, v);
    cout<<-1;
}
void loadinput()
{
    cin>>v>>n>>m;
    for(int i=1; i<=n; ++i)
        cin>>p[i];
}
int main()
{
    faster;
    //file();
    loadinput();
    solve();
    return 0;
}
