class Solution {
public:
    int mod=1e9+7;
    int helper(int i, int searchCost, int max, int n, int m, int k,vector<vector<vector<int>>>&dp){
        if(i==n){
            return  searchCost==k;
        }
        if(dp[i][searchCost][max] !=-1){
            return dp[i][searchCost][max];
        }
        int res=0;
        for(int j=1;j<=m;j++){
            if(j>max){
                res=(res+helper(i+1,searchCost+1,j,n,m,k,dp))%mod;
            } else {
                res=(res+helper(i+1,searchCost,max,n,m,k,dp))%mod;
            }
        }
        return dp[i][searchCost][max]=res%mod;
    }
    int numOfArrays(int n, int m, int k) {
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(n+1,vector<int>(m+1,-1)));
        return helper(0,0,0,n,m,k,dp);
    }
};