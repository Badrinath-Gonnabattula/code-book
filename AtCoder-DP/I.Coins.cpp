#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

int n;
long double p[3000];
long double dp[3000][3000];

long double rec(int level,int head){
    if(level==n){
        if(2*head>n) return 1;
        else return 0;
    }

    if(dp[level][head]!=-1){
        return dp[level][head];
    }

    long double ans = rec(level+1,head+1)*p[level]+rec(level+1,head)*(1-p[level]);

    return dp[level][head] = ans;
}

void solve(){
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>p[i];
    }

    for(int i=0;i<3000;i++){
        for(int j=0;j<3000;j++){
            dp[i][j] = -1;
        }
    }

    long double ans = 0;

    ans = rec(0,0);

    cout<<fixed<<setprecision(9)<<ans<<"\n";
}

signed main(){
    fast

    int t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}
