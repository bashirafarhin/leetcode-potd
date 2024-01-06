class Solution {
    int solve(vector<vector<int>>& grid,int row,int col,vector<vector<int>>&dp){
        if(row<0 || col<0){
            return 1e9;
        }
        if (row==0 && col==0){
            return grid[0][0];
        }
        if(dp[row][col] !=-1){return dp[row][col];}
        int left=solve(grid,row,col-1,dp);
        int up=solve(grid,row-1,col,dp);
        return dp[row][col]=grid[row][col]+min(left,up);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        vector<vector<int>> dp(r,vector<int>(c,-1));
        return solve(grid,r-1,c-1,dp);
    }
};