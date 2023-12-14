class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
     int Row=grid.size();
     int Col=grid[0].size();
     vector<vector<int>> diff(Row,vector<int>(Col,0));
     vector<int> Rowz(Row,0);
     vector<int> Colz(Col,0);

     for(int i=0;i<Row;i++){
         int count0=0;
         for(int j=0;j<Col;j++){
           if(!grid[i][j]){count0++;}
         }
         Rowz[i]=count0;}
     for(int i=0;i<Col;i++){
         int count0=0;
         for(int j=0;j<Row;j++){
           if(!grid[j][i]){count0++;}
         }
         Colz[i]=count0;}

     for(int i=0;i<Row;i++){
         for(int j=0;j<Col;j++){
        diff[i][j]=Col+Row-2*Rowz[i]-2*Colz[j] ; }}
     return diff;
    }
};