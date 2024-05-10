class Solution {
public:

    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int R=grid.size();
        int C=grid[0].size();
        vector<vector<int>>dp(R,vector<int>(C,0));

        for(int r=0;r<R;r++){
            for(int c=0;c<C;c++){
                if(grid[r][c]==1){ continue; }
                else if( r==0 && c==0 ){ dp[r][c]=1; }
                else{
                   if(r-1>=0){ dp[r][c]+=dp[r-1][c]; }
                   if(c-1>=0){ dp[r][c]+=dp[r][c-1]; }
                }
            }
        }
        return dp[R-1][C-1];
    }
};