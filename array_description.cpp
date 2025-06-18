#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n , k;
    cin >> n >> k;
    vector<int>v(n);
    vector<vector<int>>dp(n + 1 , vector<int>(k + 1 , 0));
    for(int &i : v) cin >> i;
    if(v[0] == 0) for(int i = 1; i <= k; i++) dp[1][i] = 1;
    dp[1][v[0]] = 1;
    for(int i = 2; i <= n; i++){
        for(int j = 1; j <= k; j++){
            if(v[i - 1] == 0 || v[i - 1] == j){
                for(int dif = -1; dif <= 1; dif++){
                    int cur = j + dif;
                    if(cur >= 1 && cur <= k) dp[i][j] = (dp[i - 1][cur] % mod + dp[i][j] % mod ) % mod;
                }
            }else{
                dp[i][j] = 0;
            }
        }
    }
    int ans = 0;
for (int j = 1; j <= k; j++) ans = (ans + dp[n][j]) % mod;
cout << ans;
