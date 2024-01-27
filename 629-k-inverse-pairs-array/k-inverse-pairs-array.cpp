class Solution {
    int mod=1e9+7;
    int solve(int n,int k,vector<vector<int>>&dp){
        if(k==0){return 1;}
        if(n==0){return 0;}
        if(dp[n][k] !=-1){return dp[n][k];}
        int count=0;
        for(int i=0;i<=min(k,n-1);i++){
            count=( count + solve (n-1,k-i,dp) )% mod;
        }
        return dp[n][k]=count;
    }
public:
    int kInversePairs(int n, int k) {
        vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
        return solve(n,k,dp);
    }
};