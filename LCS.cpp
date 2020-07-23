#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define mod 1000000007
#define vll vector<ll>

ll ti[3001][3001];


int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string s,t;
	cin>>s>>t;

	for(ll i=0;i<=s.size();i++)
    {
        for(ll j=0;j<=t.size();j++)
        {
            if(i==0 || j==0)
                ti[i][j]=0;

            else if(s[i-1]==t[j-1])
                ti[i][j]=ti[i-1][j-1]+1;

            else
                ti[i][j]=max(ti[i][j-1],ti[i-1][j]);
        }
    }
    string ans="";

    ll i=s.size(),j=t.size();

    while(i>0 && j>0)
    {
        if(s[i-1]==t[j-1])
           {
               ans+=string(1,s[i-1]);i--;j--;
           }
        else
        {
            if(ti[i][j-1]>ti[i-1][j])
                j--;
            else i--;
        }
    }
    reverse(ans.begin(),ans.end());
    cout<<ans<<endl;


	return 0;
}

