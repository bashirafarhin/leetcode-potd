class Solution {
    void bfs(int R,int C,vector<vector<int>> &visited,vector<vector<char>>& grid){
     int n=grid.size();
     int m=grid[0].size();
     queue<pair<int,int>> q;
     q.push({R,C});
     while(!q.empty()){
      int r=q.front().first;
      int c=q.front().second;
      q.pop();
      int dx[]={-1,0,1,0};
      int dy[]={0,1,0,-1};
      for(int i=0;i<4;i++){
          int new_row=r+dx[i];
          int new_col=c+dy[i];
       if(new_row>=0 && new_row<n && new_col>=0 && new_col<m && !visited[new_row][new_col] && grid[new_row][new_col]=='1'){
         q.push({new_row,new_col});
         visited[new_row][new_col]=1;
       }
      }
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
                 bfs(i,j,visited,grid);
             }
         }
     }
     return ans;   
    }
};