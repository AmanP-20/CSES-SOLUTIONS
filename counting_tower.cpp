#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    vector<vector<int>>dp(1e6 + 2 , vector<int>(2));
        dp[1][0] = 1;
        dp[1][1] = 1;
        for(int i = 2; i <= 1e6+1; i++){
            dp[i][0] = (2LL*dp[i - 1][0] + dp[i - 1][1]) % mod;
            dp[i][1] = (dp[i - 1][0] + 4LL*dp[i - 1][1]) % mod;
        }
    while(t--){
        int n; cin >> n;
        cout << (dp[n][0] + dp[n][1]) % mod << endl;
    }
}