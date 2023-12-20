class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
     int Row=grid.size();
     int Col=grid[0].size();
     for(int i=0;i<Row;i++){
         if(grid[i][0]==0){
             for(int j=0;j<Col;j++){
              if(grid[i][j]==0){grid[i][j]=1;} else {grid[i][j]=0;}}
      }
     }
     for(int c=0;c<Col;c++){
         int nz=0;
         int no=0;
         for(int r=0;r<Row;r++){
          if(grid[r][c]==0){nz++;} else {no++;}}
         
         if(nz>no){
          for(int r=0;r<Row;r++){
           if(grid[r][c]==0){grid[r][c]=1;} else {grid[r][c]=0;}}     
         }
     }
     int sum=0;
     for(int i=0;i<Row;i++){
         int num=0;
         int x=1;
         for(int j=Col-1;j>=0;j--){
          num=num+ grid[i][j]*x ;
          x=x*2;
         }
         sum+=num;
     }
     return sum;
    }
};