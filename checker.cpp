/* ****GT_18**** */

#include<bits/stdc++.h>
#define int         long long
#define ll 			long long
#define pb          push_back
#define	endl		'\n'
#define pii         pair<int,int>
#define vi          vector<int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (int)x.size()
#define hell        1000000007
#define rep(i,a,b)	for(int i=a;i<b;i++)
#define dep(i,a,b)	for(int i=a;i>=b;i--)
#define lbnd        lower_bound
#define ubnd        upper_bound
#define bs          binary_search
#define mp          make_pair
using namespace std;

#define N  100005


signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int TESTS=1;
//	cin>>TESTS;
	while(TESTS--)
	{
		ifstream gen,sol;
		gen.open("input.txt");
		sol.open("sol.txt");
		ll n,k,s=0;
		gen>>n>>k;
		string ss;
		sol>>ss;
		if(ss=="NO")
			return cout<<"No answer",0;
		vi ans(k);
		rep(i,0,k)
		{
			sol>>ans[i];
			s+=ans[i];
			if(!check(ans[i]))
			{
				cout<<"NO\n";
				return 0;
			}
		}
		if(s==n)
			cout<<"YES";
		else
			cout<<"NO";
		cout<<endl;
	}
	return 0;
}