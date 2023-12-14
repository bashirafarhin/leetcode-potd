class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
     int Row=grid.size();
     int Col=grid[0].size();
     vector<int> Rowz(Row,0);
     vector<int> Colz(Col,0);

     for(int i=0;i<Row;i++){
         for(int j=0;j<Col;j++){
           if(!grid[i][j]){Rowz[i]++;Colz[j]++;}
         }}
   

     for(int i=0;i<Row;i++){
         for(int j=0;j<Col;j++){
        grid[i][j]=Col+Row-2*Rowz[i]-2*Colz[j] ; }}
     return grid;
    }
};