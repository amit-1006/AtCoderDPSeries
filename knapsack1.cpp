#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define mod 1000000007
#define vll vector<ll>
ll val[105],wt[105],ti[105][100005];

ll func(ll len,ll w)
{
    if(len<=0 || w<=0) return 0;

    if(ti[len][w]!=-1) return ti[len][w];

    if(wt[len]<=w)
    {
       return ti[len][w]= max(val[len]+func(len-1,w-wt[len]),func(len-1,w));
    }
    else
       return ti[len][w]=func(len-1,w);

}


int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n,w;
	cin>>n>>w;
	memset(ti,-1,sizeof ti);
	for(ll i=1;i<=n;i++)
        cin>>wt[i]>>val[i];

    ll ans=func(n,w);
    cout<<ans<<endl;

	return 0;
}

