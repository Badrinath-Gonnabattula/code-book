#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

int n,W;
int w[101];
int v[101];
int dp[101][100100];


int rec(int level,int cursum){
    if(level>=n){
        return 0;
    }

    if(dp[level][cursum]!=-1){
        return dp[level][cursum];
    }

    int ans = 0;

    if(cursum+w[level] <= W){
        ans = max(ans,rec(level+1,cursum+w[level])+v[level]);
    }
    
    ans = max(ans,rec(level+1,cursum));

    return dp[level][cursum] = ans;
}

void solve(){
    cin>>n>>W;

    for(int i=0;i<n;i++){
        cin>>w[i]>>v[i];
    }

    memset(dp,-1,sizeof(dp));

    cout<<rec(0,0)<<"\n";

}

signed main(){
    fast

    int t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}
