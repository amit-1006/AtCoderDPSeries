#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define mod 1000000007
#define vll vector<ll>

ll ti[5][100001];

ll fmax(ll x,ll y,ll z)
{
    vll v;
    v.pb(x);v.pb(y);v.pb(z);
    sort(v.rbegin(),v.rend());
    return v[0];
}

ll n,a[100001],b[100001],c[100001];

ll func(ll pre,ll len)
{
    if(len==0) return 0;

    if(ti[pre][len]!=-1) return ti[pre][len];

  if(pre==0)
   return ti[pre][len]=fmax(a[len-1]+func(1,len-1),b[len-1]+func(2,len-1),c[len-1]+func(3,len-1));
  else if(pre==1)
    return ti[pre][len]=max(b[len-1]+func(2,len-1),c[len-1]+func(3,len-1));
  else if(pre==2)
    return ti[pre][len]=max(a[len-1]+func(1,len-1),c[len-1]+func(3,len-1));
  else
    return ti[pre][len]=max(a[len-1]+func(1,len-1),b[len-1]+func(2,len-1));

}


int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    memset(ti,-1,sizeof ti);
	//ll n;
	cin>>n;

	for(ll i=0;i<n;i++)
        cin>>a[i]>>b[i]>>c[i];

      cout<<func(0,n)<<endl;;

	return 0;
}

