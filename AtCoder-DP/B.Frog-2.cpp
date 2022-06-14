#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

int n,k;
int arr[100100];
int dp[100100];

int rec(int level){
    if(level<0){
        return 1e9;
    }

    if(dp[level]!=-1){
        return dp[level];   
    }

    int ans = 1e9;

    for(int i=1;i<=k;i++){
        ans = min(ans,rec(level-i)+abs(arr[level] - arr[level-i]));
    }

    return dp[level] = ans;
}

void solve(){
    cin>>n>>k;

    for(int i=0;i<n;i++){
        cin>>arr[i];
        dp[i] = -1;
    }

    dp[0] = 0;

    cout<<rec(n-1)<<"\n";

}

signed main(){
    fast

    int t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}