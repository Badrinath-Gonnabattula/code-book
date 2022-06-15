#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define mod 1000000007

int n,m;
char arr[1001][1001];
int dp[1001][1001];

int rec(int i,int j){
    if(i<0 or i>=n or j<0 or j>=m){
        return 0;
    }

    if(arr[i][j]=='#'){
        return 0;
    }

    if(i==0 and j==0){
        return 1;
    }

    if(dp[i][j]!=-1){
        return dp[i][j];
    }

    int ans = (rec(i-1,j)%mod + rec(i,j-1)%mod)%mod;

    return dp[i][j] = ans%mod;
}

void solve(){
    cin>>n>>m;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }

    for(int i=0;i<1001;i++){
        for(int j=0;j<1001;j++){
            dp[i][j] = -1;
        }
    }

    if(arr[0][0]=='#' or arr[n-1][m-1]=='#'){
        cout<<0<<"\n";
        return;
    }

    cout<<rec(n-1,m-1)<<"\n";
}

signed main(){
    fast

    int t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}