#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define mod 1000000007
#define vll vector<ll>

ll ti[100001];
vll g[100001];ll vis[100001];


ll n,m;

void dfs(ll n)
{
    vis[n]=1;
    for(auto child:g[n])
    {
        if(vis[child]==0)
            dfs(child);

        ti[n]=max(ti[n],1+ti[child]);
    }
}

ll func(ll v)
{
    if(g[v].size()==0)
        return 0;

    if(ti[v]!=-1) return ti[v];

    ll mx=0;
   for(ll i=0;i<g[v].size();i++)
   {
       mx=max(mx,1+func(g[v][i]));
   }
   return ti[v]=mx;
}


int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    memset(ti,0,sizeof ti);
	//ll n;
	cin>>n>>m;
	ll a,b;

	for(ll i=0;i<m;i++){
        cin>>a>>b;
        g[a].pb(b);
	}

	for(ll i=1;i<=n;i++)
    {
        if(vis[i]!=1)
            dfs(i);
    }
    ll mx=0;
    for(ll i=1;i<=n;i++)
        mx=max(mx,ti[i]);

    cout<<mx<<endl;

	return 0;
}

