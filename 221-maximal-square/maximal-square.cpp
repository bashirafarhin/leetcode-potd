class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        vector<vector<int>> dp(r, vector<int>(c, 0));
        int len = 0;
        for (int i = r - 1; i >= 0; i--) {
            for (int j = c - 1; j >= 0; j--) {
                if (i == r - 1 || j == c - 1) {
                    dp[i][j] = matrix[i][j] - '0';
                } else if (matrix[i][j] == '1') {
                    dp[i][j] =
                        min({dp[i][j + 1], dp[i + 1][j + 1], dp[i + 1][j]}) + 1;
                }
                len = max(len, dp[i][j]);
            }
        }
        return len * len;
    }
};