#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
#define For(i, n) for (ll i = 0; i < n; i++)
#define ll long long
typedef vector<ll> vl;
typedef vector<int> vi;
#define crl(x) ll x; cin >> x;
#define cr(x) int x; cin >> x;
const int mod = 998244353;
 
int main(){
    cr(n) cr(x)
    vi weight(n),cost(n);
    For(i,n) cin>>weight[i];
    For(i,n) cin>>cost[i];
    vector<int>dp(x+1,0);
    for(int i= 0; i < n; i++){
        for(int j = x;j>=weight[i]; j--){
            dp[j] = max(dp[j],dp[j-weight[i]]+cost[i]);
        }
    }
    cout<<dp[x];
}