class Solution {
public:
    int solve(vector<vector<int>>& grid, int i, int j) {
        if (i<0 || i == grid.size() || j<0 || j == grid[0].size() || grid[i][j] == 0) {
            return 0;
        }

        int gold=grid[i][j];
        grid[i][j]=0;
        int left = solve(grid, i, j - 1);
        int up = solve(grid, i - 1, j);
        int right = solve(grid, i, j + 1);
        int down = solve(grid, i + 1, j);
        grid[i][j]=gold;

        return grid[i][j] + max(left, max(right, max(up, down)));
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();        
        int ans = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                ans = max(ans, solve(grid, i, j));
            }
        }
        return ans;
    }
};