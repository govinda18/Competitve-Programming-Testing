#include "testlib.h"
#include<bits/stdc++.h>
#define ll             long long
#define pb          push_back
#define endl        '\n'
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

void writeTest(int test)
{
    startTest(test);
    cout<<rnd.next(5);
}

signed main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    int tests=stoi(argv[1]);
    for (int i = 0; i < tests; i++)
        writeTest(i);    
    return 0;
}
