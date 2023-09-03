class Solution {
public:
    int solve(vector<vector<int>>&dp,int m,int n){
        if(n<0 || m<0){return 0;}
        if(m==0 && n==0){return 1;}
        if(dp[m][n] !=-1){return dp[m][n];}
        int left=solve(dp,m,n-1);
        int up=solve(dp,m-1,n);
        return dp[m][n]=left+up;
    }
    int uniquePaths(int m, int n) {
     vector<vector<int>> dp(m,vector<int>(n,-1));
     return solve(dp,m-1,n-1);
    }
};