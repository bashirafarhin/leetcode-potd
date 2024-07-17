class Solution {
public:
    int solve(int c1,int c2,int r,vector<vector<int>>& grid,vector<vector<vector<int>>>&dp){
        if(c1<0 || c2<0 || c1==grid[0].size() || c2==grid[0].size() || r==grid.size()){ return 0; }
        if(dp[c1][c2][r] !=-1){
            return dp[c1][c2][r];
        }
        int cherries=0;
        if(c1==c2){
            cherries+=grid[r][c1];
        } else {
            cherries+=grid[r][c1]+grid[r][c2];
        }
        int chr1=grid[r][c1];
        int chr2=grid[r][c2];
        grid[r][c1]=0;
        grid[r][c2]=0;

        int ans=0;
        for(int i=-1;i<=1;i++){
            for(int j=-1;j<=1;j++){
                ans=max(ans , solve(c1+i,c2+j,r+1,grid,dp));
            }
        }

        grid[r][c1]=chr1;
        grid[r][c2]=chr2;
        return dp[c1][c2][r]=cherries+ans;
        
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int c=grid[0].size();
        int r=grid.size();
        vector<vector<vector<int>>>dp(c,vector<vector<int>>(c,vector<int>(r,-1)));
        return solve(0,c-1,0,grid,dp);
    }
};