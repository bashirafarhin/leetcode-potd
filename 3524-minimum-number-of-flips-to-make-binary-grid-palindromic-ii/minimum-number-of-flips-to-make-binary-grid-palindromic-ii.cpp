class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int changes = 0;
        for (int r = 0; r < row / 2; r++) {
            for (int c = 0; c < col / 2; c++) {
                int ones = grid[r][c] + grid[r][col - c - 1] +
                           grid[row - r - 1][c] +
                           grid[row - r - 1][col - c - 1];
                if (ones > 4 - ones) {
                    changes += (4 - ones);
                } else {
                    changes += ones;
                }
            }
        }
        int countPairOf1s = 0;
        int count=0;
        if (row % 2 != 0) {
            for (int c = 0; c < col / 2; c++) {
                if(grid[row / 2][c] != grid[row / 2][col - c - 1]){
                    changes++;
                    count++;
                } else if(grid[row / 2][c] == grid[row / 2][col - c - 1] && grid[row / 2][c]){
                    countPairOf1s++;
                }
            }
        }
        if (col % 2 != 0) {
            for (int r = 0; r < row / 2; r++) {
                if(grid[r][col / 2] != grid[row - r - 1][col / 2]){
                    changes++;
                    count++;
                } else if(grid[r][col / 2] == grid[row - r - 1][col / 2] && grid[r][col / 2]){
                    countPairOf1s++;
                }
            }
        }

        if((countPairOf1s % 2) && count==0){ changes+=2; }
        if (row % 2 != 0 && col % 2 != 0 && grid[row / 2][col / 2] == 1) { changes++; }
        return changes;
    }
};