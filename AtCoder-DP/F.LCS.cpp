#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

string s1,s2;
int n,m;
vector<vector<int>> dp;

int rec(int i,int j){
    if(i>=n or j>=m) return 0;

    if(dp[i][j]!=-1) return dp[i][j];

    int ans = 0;
    if(s1[i]==s2[j]){
        ans = max(ans,1+rec(i+1,j+1));
    }
    else{
        ans = max(ans,rec(i+1,j));
        ans = max(ans,rec(i,j+1));
    }

    return dp[i][j] = ans;
}

string ans;
void print_sol(int i,int j){
    if(i==n or j==m) return;

    if(rec(i,j)==rec(i+1,j)){
        print_sol(i+1,j);
    }
    else if(rec(i,j)==rec(i,j+1)){
        print_sol(i,j+1);
    }
    else{
        ans+=s1[i];
        print_sol(i+1,j+1);
    }
}

void solve(){
    cin>>s1;cin>>s2;
    n = s1.length();
    m = s2.length();
    
    dp.clear();dp.resize(n+1);
    for(int i=0;i<=n;i++){
        dp[i].assign(m+1,-1);
    }
    int lcs = rec(0,0);
    print_sol(0,0);
    cout<<ans<<"\n";
}

signed main(){
    fast

    int t=1;

    while(t--){
        solve();
    }
}
