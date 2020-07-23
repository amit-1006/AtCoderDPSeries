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


ll n,a[100001];

ll func(ll pre)
{
   if(pre<0) return 1e16;
   if(pre==0) return 0;
   if(ti[pre]!=-1) return ti[pre];


   return ti[pre]=min(abs(a[pre-2]-a[pre])+func(pre-2),abs(a[pre-1]-a[pre])+func(pre-1));
}


int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    memset(ti,-1,sizeof ti);
	//ll n;
	cin>>n;

	for(ll i=0;i<n;i++)
        cin>>a[i];

      cout<<func(n-1)<<endl;;

	return 0;
}

