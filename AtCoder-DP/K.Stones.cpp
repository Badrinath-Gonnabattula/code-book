#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);


int n,k;
int a[101];
int dp[100100];

int rec(int K){
    if(K==0){
        return 0;
    }

    if(dp[K]!=-1){
        return dp[K];
    }

    int ans = 0;

    for(int i=0;i<n;i++){
        if(a[i]<=K and rec(K-a[i])==0){
            ans = 1;
            break;
        }
    }

    return dp[K] = ans;
}

void solve(){
    cin>>n>>k;

    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    memset(dp,-1,sizeof(dp));

    bool who = rec(k);

    if(who==1){
        cout<<"First"<<"\n";
    }
    else{
        cout<<"Second"<<"\n";
    }
}

signed main(){
    fast

    int t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}
