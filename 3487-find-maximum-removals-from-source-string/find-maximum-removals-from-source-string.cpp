class Solution {
public:
    // T(k)=O(n+m)×2^(length of targetIndices)-brute force

    int helper(int i, int j, string& src, string& pat, vector<int>& ind, vector<vector<int>>& dp) {
        if (i == src.size()) {
            return j == pat.size() ? 0 : INT_MIN;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        int ans = helper(i + 1, j, src, pat, ind, dp);
        ans = max(ans, ind[i] + helper(i + 1, j, src, pat, ind, dp));
        if (src[i] == pat[j]) {
            ans = max(ans, helper(i + 1, j + 1, src, pat, ind, dp));
        }
        return dp[i][j] = ans;
    }

    int maxRemovals(string source, string pattern, vector<int>& targetIndices) {
        int n = source.size();
        int m = pattern.size();
        vector<int> ind(n, 0);
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        for (int index : targetIndices) {
            ind[index] = 1;
        }
        return helper(0, 0, source, pattern, ind, dp);
    }
};