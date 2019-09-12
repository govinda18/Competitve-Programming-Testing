/* Dsingh_24 */

#include<bits/stdc++.h>
#define ll          long long
#define pb          push_back
#define endl        '\n'
#define pii         pair<ll int,ll int>
#define vi          vector<ll int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (ll int)x.size()
#define hell        1000000007
#define rep(i,a,b)  for(ll int i=a;i<b;i++)
#define lbnd        lower_bound
#define ubnd        upper_bound
#define bs          binary_search
#define mp          make_pair
#define ios     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;


int minStep(string str) 
{ 
    int N = str.length(); 
    int dp[N + 1][N + 1]; 
    for (int i = 0; i <= N; i++) 
        for (int j = 0; j <= N; j++) 
            dp[i][j] = 0; 
    for (int len = 1; len <= N; len++) 
    {
        for (int i = 0, j = len - 1; j < N; i++, j++) 
        { 
            if (len == 1) 
                dp[i][j] = 1; 
            else
            { 
                dp[i][j]=min(1+dp[i+ 1][j],1+dp[i][j-1]); 
  
                if (str[i] == str[i + 1]) 
                    dp[i][j] = min(dp[i + 1][j], dp[i][j]); 
                 if (str[j] == str[j - 1]) 
                    dp[i][j] = min(dp[i][j-1], dp[i][j]); 
                for (int K = i + 2; K <= j; K++) 
                    if (str[i] == str[K]) 
                        dp[i][j] = min(dp[i+1][K-1] + dp[K+1][j] +((dp[i+1][K-1]==dp[i][K-1]||dp[i+1][K-1]==dp[i+1][K])?0:1) ,
                                                       dp[i][j]); 
    
            } 
        } 
    } 
    return dp[0][N - 1]; 
}
int main()
{
    ios
    ll n,i,j;
    cin>>n;
    string s;
    cin>>s;
    ll ans=minStep(s);
    cout<<ans;
    return 0;
}