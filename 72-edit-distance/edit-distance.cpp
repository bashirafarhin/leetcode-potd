class Solution {
public:
    int solve(string word1, string word2, int i, int j,
              vector<vector<int>>& dp) {
        if (i == word1.size() && j == word2.size()) {
            return 0;
        }
        if (i == word1.size()) {
            return word2.size()-j;
        }
        if (j == word2.size()) {
            return word1.size()-i;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        if (word1[i] == word2[j]) {
            return dp[i][j] = solve(word1, word2, i + 1, j + 1, dp);
        }
        return dp[i][j] = min(1 + solve(word1, word2, i + 1, j, dp),
                              min(1 + solve(word1, word2, i, j + 1, dp),
                                  1 + solve(word1, word2, i + 1, j + 1, dp)));
    }
    int minDistance(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        vector<vector<int>> dp(n1, vector<int>(n2, -1));
        return solve(word1, word2, 0, 0, dp);
    }
};