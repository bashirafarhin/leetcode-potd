class Solution {
public:
    // r1+c1==r2+c2
    int solve(int r1,int c1,int r2,vector<vector<int>>& grid,vector<vector<vector<int>>>&dp){
        int c2=r1+c1-r2;
        if( r1==grid.size() || r2==grid.size() || c1==grid[0].size() || c2==grid[0].size() || grid[r1][c1]==-1 || grid[r2][c2]==-1){
            return INT_MIN;
        }

        if(r1==grid.size()-1 && c1==grid[0].size()-1){
            return grid[r1][c1];
        }

        if(dp[r1][c1][r2] !=-1){
            return dp[r1][c1][r2];
        }
        

        int cherry=0;
        if(r1==r2 && c1==c2){
            cherry=grid[r1][c1];
        } else {
            cherry=grid[r1][c1]+grid[r2][c2];
        }

        int hh=solve(r1,c1+1,r2,grid,dp);
        int vh=solve(r1+1,c1,r2,grid,dp);
        int vv=solve(r1+1,c1,r2+1,grid,dp);
        int hv=solve(r1,c1+1,r2+1,grid,dp);
        return dp[r1][c1][r2]=cherry+max({ hh,vh,vv,hv });
    }

    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(n,vector<int>(n,-1)));
        return max(solve(0,0,0,grid,dp),0);
    }
};