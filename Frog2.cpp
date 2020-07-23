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


ll n,a[100001],k;

ll func(ll pre)
{
   if(pre<0) return 1e16;
   if(pre==0) return 0;
   if(ti[pre]!=-1) {return ti[pre];}
ll mn=1e16;
   for(ll i=1;i<=k;i++){
        if(pre-i<0) break;
      mn=min(mn,abs(a[pre-i]-a[pre])+func(pre-i));
   }
   return ti[pre]=mn;
}


int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    memset(ti,-1,sizeof ti);
	//ll n;
	cin>>n>>k;

	for(ll i=0;i<n;i++)
        cin>>a[i];

      cout<<func(n-1)<<endl;
      //cout<<mn<<endl;;

	return 0;
}

