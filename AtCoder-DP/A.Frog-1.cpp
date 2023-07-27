#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

int n;
vector<int> arr,dp;

int rec(int level){
    if(level<1) return 0;
    if(level==1) return abs(arr[level]-arr[level-1]);

    if(dp[level]!=-1) return dp[level];

    int ans = abs(arr[level]-arr[level-1])+rec(level-1);
    ans = min(ans,abs(arr[level]-arr[level-2])+rec(level-2));

    return dp[level] = ans;
}

void solve(){
    cin>>n;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
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
