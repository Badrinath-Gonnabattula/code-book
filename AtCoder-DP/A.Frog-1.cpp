#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

int n;
int arr[100100];
int dp[100100];

int rec(int level){
    if(level<0){
        return 0;
    }

    if(dp[level]!=-1){
        return dp[level];
    }

    int ans = min(rec(level-1)+abs(arr[level-1]-arr[level]),rec(level-2)+abs(arr[level-2]-arr[level]));

    return dp[level] = ans;
}

void solve(){
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>arr[i];
        dp[i] = -1;
    }
    
    dp[0] = 0;
    dp[1] = abs(arr[1] - arr[0]);

    cout<<rec(n-1)<<"\n";
}

signed main(){
    fast

    int t=1;

    while(t--){
        solve();
    }
}