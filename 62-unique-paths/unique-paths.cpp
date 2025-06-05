class Solution {
public:
    int allWays(int r, int c, vector<vector<int>>&dp){
        if(r==0 && c==0){ return 1; }
        if(r<0 || c<0){ return 0; }
        if(dp[r][c] !=-1){ return dp[r][c]; }
        return dp[r][c]=allWays(r-1,c,dp)+allWays(r,c-1,dp);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return allWays(m-1,n-1,dp);
    }
};