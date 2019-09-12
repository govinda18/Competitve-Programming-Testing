#include<bits/stdc++.h>
#define int			long long
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
		int n;
		cin>>n;
		vector<int> v(n+2);
		for(int i=1;i<=n;i++)
			cin>>v[i];
		int ans=-1e18;
		for(int i=1;i<=sqrt(n);i++)
		{
			if(n%i==0)
			{
				if(n/i>2)
					for(int j=1;j<=i;j++)
					{
						int cur=0;
						for(int k=j;k<=n;k+=i)
							cur+=v[k];
						ans=max(ans,cur);
					}
				int x=n/i;
				if(i>2)
					for(int j=1;j<=x;j++)
					{
						int cur=0;
						for(int k=j;k<=n;k+=x)
							cur+=v[k];
						ans=max(ans,cur);
					}

			}
		}		
		cout<<ans;
	}
	return 0;
}