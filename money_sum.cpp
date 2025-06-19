#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    vector<int> v(n);
    for (int &i : v) cin >> i;
    int sum = accumulate(v.begin(),v.end(),0);
    vector<bool>dp(sum + 1 , false);
    dp[0] = 1;
    for(int i : v){
        for(int j = sum; j >= i; j--) dp[j] = dp[j]|dp[j - i];
    }
    int ct = 0;
    for(int i = 1; i <= sum; i++) if(dp[i])ct++;
    cout << ct << endl;
    for(int i = 1; i <= sum; i++) if(dp[i]) cout << i << " ";
}
