#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a , b;
    cin >> a >> b;
    vector<vector<int>>dp(a + 1 , vector<int>(b + 1, INT_MAX));
    for(int i = 0; i <= a; i++){
        for(int j = 0; j <= b; j++){
            if(i != j){
                //for minimum cut of size i x j we can either cut vertically or horizontally from till i - 1 or j - 1
                //so for i x j we can make it i x k and i x (j - k)
                for(int k = 1; k < i; k++){
                    dp[i][j] = min(dp[i][j] , dp[k][j] + dp[i - k][j] + 1);
                }
                for(int k = 1; k < j; k++){
                    dp[i][j] = min(dp[i][j] , dp[i][k] + dp[i][j - k] + 1);
                }
            }
            else dp[i][j] = 0; // if i == j then already a square, no cuts needed
        }
    }
    cout << dp[a][b] << endl;
