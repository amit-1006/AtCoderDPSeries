#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define mod 1000000007
#define vll vector<ll>
ll val[105],wt[105],ti[100005][105];

ll func(ll sum,ll len)
{
    if(sum<=0) return 0;
    if(len<=0) return 1e16;

    if(ti[sum][len]!=-1) return ti[sum][len];

   return ti[sum][len]=min(func(sum,len-1),wt[len]+func(sum-val[len],len-1));

}


int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n,w;
	cin>>n>>w;
	ll sum=0;
	memset(ti,-1,sizeof ti);
	for(ll i=1;i<=n;i++){
        cin>>wt[i]>>val[i];
        sum+=val[i];
	}

    for(ll i=sum;i>=0;i--)
    {
        if(func(i,n)<=w)
        {
            cout<<i<<endl;
            exit(0);
        }
    }
    cout<<"0"<<endl;

  //  ll ans=func(n,w);
   // cout<<ans<<endl;

	return 0;
}

