#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

int n;
int a[100100];
int b[100100];
int c[100100];
int dp[100100][3];

int rec(int level,int prev){
    if(level>=n){
        return 0;
    }

    if(dp[level][prev]!=-1){
        return dp[level][prev];
    }

    int ans = 0;

    if(prev==0){
        ans = max(rec(level+1,1)+b[level],rec(level+1,2)+c[level]);
    }
    else if(prev==1){
        ans = max(rec(level+1,0)+a[level],rec(level+1,2)+c[level]);
    }
    else{
        ans = max(rec(level+1,1)+b[level],rec(level+1,0)+a[level]);
    }

    return dp[level][prev] = ans;
}


void solve(){
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i]>>c[i];
        dp[i][0] = -1;
        dp[i][1] = -1;
        dp[i][2] = -1;
    }

    cout<<max({rec(0,0),rec(0,1),rec(0,2)})<<"\n";
}

signed main(){
    fast

    int t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}