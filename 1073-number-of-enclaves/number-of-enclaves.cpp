class Solution {
     int dx[4]={0,1,0,-1};
    int dy[4]={1,0,-1,0};
     void dfs(int row, int col,vector<vector<int>> &grid){
        grid[row][col]=-1;
        for(int i=0; i<4; i++){
            int newX=row+dx[i];
            int newY=col+dy[i];
            if(newX>=0 && newY>=0 && newX<grid.size() 
            && newY<grid[0].size() && grid[newX][newY]==1){
                dfs(newX,newY,grid);
            }
        }}
public:
    int numEnclaves(vector<vector<int>>& grid) {
         int n=grid.size();
        int m=grid[0].size();
        for(int i=0; i<n; i++){
            //1 col
            if(grid[i][0]==1){
                dfs(i,0,grid);
            }
            //last col
            if(grid[i][m-1]==1){
                dfs(i,m-1,grid);
            }
        }
        for(int i=0; i<m; i++){
            //1 row
            if(grid[0][i]==1){
                dfs(0,i,grid);
            }
            //last row
            if(grid[n-1][i]==1){
                dfs(n-1,i,grid);
            }
        }
        int cnt=0;
        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){
                if(grid[i][j]==1){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};