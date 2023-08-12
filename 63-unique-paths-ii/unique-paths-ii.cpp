class Solution {
public:
    int solve(vector<vector<int>>& obstacleGrid,int r,int c,vector<vector<int>> &dp){
        if(r<0 || c<0 || obstacleGrid[r][c]==1){return 0;}
        if(r==0 && c==0)
        {return 1;}
        if(dp[r][c]==-1){
        int left=solve(obstacleGrid,r,c-1,dp);
        int up=solve(obstacleGrid,r-1,c,dp);
        dp[r][c]=left+up;}
        return dp[r][c];
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
      int m=obstacleGrid.size();
      int n=obstacleGrid[0].size();
      vector<vector<int>> dp(m,vector<int>(n,-1));
      return solve(obstacleGrid,m-1,n-1,dp);
    }
};