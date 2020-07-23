#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define mod 1000000007
#define vll vector<ll>

double ti[3001][3001];ll n;
double arr[30001];

double func(ll head,ll len)
{
    if(len==0)
    {
        if(head>=(n/2+1))
            return 1;
        else return 0;
    }

    if(ti[head][len]!=-1) return ti[head][len];


    return ti[head][len]=arr[len-1]*func(head+1,len-1)+((1.0-arr[len-1])*func(head,len-1));
}


int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	//ll n;
	cin>>n;

	//double pro[n];
	for(ll i=0;i<n;i++)
        cin>>arr[i];

  for(ll i=0;i<=n;i++)
  {
      for(ll j=0;j<=n;j++)
        ti[i][j]=-1;
  }
   double ans=func(0,n);

      // cout<<ans<<endl;
      printf("%.10f",ans);
      cout<<endl;

	return 0;
}

