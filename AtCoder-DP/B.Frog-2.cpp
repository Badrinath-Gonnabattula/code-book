#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

int n,k;
vector<int> arr,dp;

int rec(int level){
    if(level<0) return 1e9;
    if(level==0) return 0;

    if(dp[level]!=-1) return dp[level];

    int ans = 1e9;
    for(int i=1;i<=k;i++){
        if(level>=i) ans = min(ans,rec(level-i)+abs(arr[level]-arr[level-i]));
    }
    
    return dp[level] = ans;
}

void solve(){
    cin>>n>>k;
    arr.clear();
    for(int i=0;i<n;i++){
        int a;cin>>a;
        arr.push_back(a);
    }
    dp.clear();dp.assign(n+1,-1);
    cout<<rec(n-1)<<"\n";
}

signed main(){
    fast

    int t=1;

    while(t--){
        solve();
    }
}
