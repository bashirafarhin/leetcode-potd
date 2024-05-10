class Solution {
public:
    int solve(vector<vector<int>>& grid,int r,int c,vector<vector<int>>& vis,vector<vector<int>>&dp){
        if(r<0 || c<0 || vis[r][c]==1 || grid[r][c]==1){ return 0; }
        if(r==0 && c==0){ return 1; }
        if(dp[r][c] !=-1){ return dp[r][c]; }
        vis[r][c]=1;
        int up=solve(grid,r-1,c,vis,dp);
        int left=solve(grid,r,c-1,vis,dp);
        vis[r][c]=0;
        return dp[r][c]=up+left;

    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int r=obstacleGrid.size();
        int c=obstacleGrid[0].size();
        vector<vector<int>>vis(r,vector<int>(c,0));
        vector<vector<int>>dp(r,vector<int>(c,-1));    
        return solve(obstacleGrid,r-1,c-1,vis,dp);
    }
};