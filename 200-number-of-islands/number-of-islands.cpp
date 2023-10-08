class Solution {
    void dfs(int r,int c,vector<vector<int>> &visited,vector<vector<char>>& grid){
     int n=grid.size();
     int m=grid[0].size();
     if(r<0 || r==n || c<0 || c==m || visited[r][c]==1 || grid[r][c]=='0'){return ;}
     int dx[]={-1,0,1,0};
     int dy[]={0,1,0,-1};
     visited[r][c]=1;
     for(int i=0;i<4;i++){
         dfs(r+dx[i],c+dy[i],visited,grid);
     }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
     int n=grid.size();
     int m=grid[0].size();
     int ans=0;
     vector<vector<int>> visited(n,vector<int>(m,0));
     for(int i=0;i<n;i++){
         for(int j=0;j<m;j++){
             if(!visited[i][j] &&  grid[i][j]=='1'){
                 ans++;
                 dfs(i,j,visited,grid);
             }
         }
     }
     return ans;   
    }
};