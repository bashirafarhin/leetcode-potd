class Solution {
public:
    int mod=1e9+7;
    int helper(int n, vector<int>&dp){
        if(n<=2){
            return n;
        }
        if(n==3){
            return 5;
        }
        if(dp[n] !=-1){
            return dp[n];
        }
        return dp[n]=(2*helper(n-1,dp)%mod+helper(n-3,dp)%mod)%mod;
    }
    int numTilings(int n) {
        vector<int>dp(n+1,-1);
        return helper(n,dp);
    }
};