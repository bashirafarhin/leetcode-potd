class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        int flips=0;
        for(int r=0;r<row/2;r++){
            for(int c=0;c<col/2;c++){
                int count1=grid[r][c]+grid[r][col-c-1]+grid[row-r-1][c]+grid[row-r-1][col-c-1];
                flips+=min(count1,4-count1);
            }
        }

        //if row is odd
        int countPairsOf1=0;
        //count of flips
        int count=0;
        if(row & 1){
            for(int c=0;c<col/2;c++){
                if(grid[row/2][c] !=grid[row/2][col-c-1]){//change 1 to 0
                  flips++;
                  count++;
                } else if(grid[row/2][c]==grid[row/2][col-c-1] && grid[row/2][c]==1) {
                  countPairsOf1++;
                }
            }
        }
        //if col is odd
        if(col & 1){
            for(int r=0;r<row/2;r++){
                if(grid[r][col/2] !=grid[row-r-1][col/2]){//change 1 to 0
                  flips++;
                  count++;
                } else if(grid[r][col/2]==grid[row-r-1][col/2] && grid[r][col/2]==1) {
                  countPairsOf1++;
                }
            }
        }
        if((countPairsOf1 & 1) && count==0){ flips+=2; }
        if((row & 1) && (col & 1) && grid[row/2][col/2]==1){ flips++; }
        return flips;
    }
};