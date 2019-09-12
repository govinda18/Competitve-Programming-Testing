#include<bits/stdc++.h>
#define int            long long
#define ll             long long
#define pb          push_back
#define    endl        '\n'
#define pii         pair<int,int>
#define vi          vector<int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (int)x.size()
#define hell        1000000007
#define rep(i,a,b)    for(int i=a;i<b;i++)
#define dep(i,a,b)    for(int i=a;i>=b;i--)
#define lbnd        lower_bound
#define ubnd        upper_bound
#define bs          binary_search
#define mp          make_pair
using namespace std;

#define N  2005

ll f[N][N];

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int TESTS=1;
  //  cin>>TESTS;
    while(TESTS--)
    {
        memset(f,0,sizeof f);
        ll n,k,ans=0;
        cin>>n>>k;
        vi a(n+1);
        rep(i,1,n+1)
        {
            cin>>a[i];
            rep(j,1,N)
            f[i][j]=f[i-1][j];
            f[i][a[i]]++;
        }
        rep(l,1,n+1)
        rep(r,l,n+1)
        {
            ll kth=k%(r-l+1);
            if(!kth)
                kth=r-l+1;
            ll x=a[l+kth-1];
            ll fr=f[r][x]-f[l-1][x];
//            cout<<l<<" "<<r<<" "<<x<<endl;
            if(f[r][fr]-f[l-1][fr]>0)
                ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
 
10 5 8 2 3 6 7 