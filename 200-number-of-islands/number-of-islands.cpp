class Solution {
public:
//observation
// 1 agar hoga to island exist hi krega
    void markIslandGrp(vector<vector<char>>&grid,int r,int c,vector<vector<int>>&vis){
        if(r<0 || r==grid.size() || c<0 || c==grid[0].size() || grid[r][c]=='0' ||  vis[r][c]){ return; }
        vis[r][c]=1;
        markIslandGrp(grid,r-1,c,vis);
        markIslandGrp(grid,r,c+1,vis);
        markIslandGrp(grid,r+1,c,vis);
        markIslandGrp(grid,r,c-1,vis);
        return; 
    }

    int numIslands(vector<vector<char>>& grid) {
        int count=0;
        int R=grid.size();
        int C=grid[0].size();
        vector<vector<int>>vis(R,vector<int>(C,0));
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    count++;
                    markIslandGrp(grid,i,j,vis);
                }
            }
        }
        return count;
    }
};