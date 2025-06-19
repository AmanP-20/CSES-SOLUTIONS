#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    long long n;
    cin >> n;
    vector<long long> v(n);
    for(long long &i : v) cin >> i;
    vector<vector<long long>>dp(n , vector<long long>(n , LLONG_MAX));
    for(long long i = 0; i < n; i++) dp[i][i] = v[i];
    for(long long i = 1; i < n; i++) v[i] += v[i - 1];
    for(long long len = 2; len <= n; len++){
        for(long long i = 0; i+len <= n; i++){
            long long r = i + len - 1;
            dp[i][r] = v[r] - (i == 0 ? 0 : v[i - 1]) - min(dp[i + 1][r] , dp[i][r - 1]);
        }
    }
    cout << dp[0][n - 1];
}
