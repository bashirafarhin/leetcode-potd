class Solution {
     void dfs(vector<vector<char>> &mat,int r,int c,vector<vector<int>>&vis){
     vis[r][c]=1;
     int dx[]={-1,0,1,0};
     int dy[]={0,1,0,-1};
     int n=mat.size();
     int m=mat[0].size();
     for(int i=0;i<4;i++){
         int newr=r+dx[i];
         int newc=c+dy[i];
         if(newr>=0 && newr<n && newc>=0 && newc<m && vis[newr][newc]==0 && mat[newr][newc]=='O')
          {dfs(mat,newr,newc,vis);}
     }
    }
public:
    void solve(vector<vector<char>>& board) {
      int n=board.size();
      int m=board[0].size();
       //O (or set of O) connected to boundary will not be converted to X
      vector<vector<int>> vis(n,vector<int>(m,0));
      for(int i=0;i<m;i++){
          //first row
          if(board[0][i]=='O' && vis[0][i]==0){dfs(board,0,i,vis);}
          //last row
          if(board[n-1][i]=='O' && vis[n-1][i]==0){dfs(board,n-1,i,vis);}
      }
      for(int i=0;i<n;i++){
          //first col
          if(board[i][0]=='O' && vis[i][0]==0){dfs(board,i,0,vis);}
          //last col
          if(board[i][m-1]=='O' && vis[i][m-1]==0){dfs(board,i,m-1,vis);}
      }
      //convert
      for(int i=0;i<n;i++){
          for(int j=0;j<m;j++){
              if(vis[i][j]==0 && board[i][j]=='O'){board[i][j]='X';}
          }
      } 
    }
};