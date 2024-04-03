class Solution {
public:
    bool isvalid(int r,int c,int R,int C){
     if(c<0 || c==C || r<0 || r==R){return false;}
        return true;
    }
    
    bool dfs(vector<vector<char>> &grid, string word,int R,int C,int row,int col,int l){
     if(l==word.length()){return true;}
     if(!isvalid(row,col,R,C) || word[l] !=grid[row][col])
      {return false;}
     
     int dx[]= { -1,  0, 0, 1 };
     int dy[]= {  0, -1, 1, 0 };
     for(int i=0;i<4;i++){
         char x=grid[row][col];
         grid[row][col]='%';
         if(dfs(grid,word,R,C,row+dx[i],col+dy[i],l+1)){
          grid[row][col]=x;  
          return true;
         }
          grid[row][col]=x;  
     }
     return false;}

    bool exist(vector<vector<char>>& board, string word) {
     int row=board.size();
	 int col=board[0].size();
	 for(int i=0;i<row;i++){
	     for(int j=0;j<col;j++){
	         if(dfs(board,word,row,col,i,j,0)){
	           return true;}
	     }
	 }
	 return false;
	
    }
};