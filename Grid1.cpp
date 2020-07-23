#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define mod 1000000007
#define vll vector<ll>

ll ti[1001][1001];
vll g[100001];ll vis[1001][1001];
char arr[1001][1001];
ll dx[2]={1,0};
ll dy[2]={0,1};


ll n,m;

ll func(ll x,ll y)
{
    if(x<1 || y<1) return 0;

    if(arr[x][y]=='#') return 0;
    if(x==1 && y==1) return 1;

    if(ti[x][y]!=-1) return ti[x][y];
   /* ll l,r;
    if(ti[x-1][y]!=-1) l=ti[x-1][r];
    else l=func(x-1,y);
    if(ti[x][y-1]!=-1) r=ti[x][y-1];
    else r=func(x,y-1);*/

      //  return ti[x][y]=l%mod+r%mod;
      return ti[x][y]=func(x-1,y)%mod+func(x,y-1)%mod;

}



int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    memset(ti,-1,sizeof ti);
	//ll n;
	cin>>n>>m;
	for(ll i=1;i<=n;i++)
    {
        for(ll j=1;j<=m;j++)
            cin>>arr[i][j];
    }
    cout<<func(n,m)%mod<<endl;

	return 0;
}

