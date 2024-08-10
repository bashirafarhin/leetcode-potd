class Solution {
public:
    int helper(int start, int end, vector<int>& cuts, vector<vector<int>>& dp) {
        if (start > end) {
            return 0;
        }
        if (dp[start][end] != -1) {
            return dp[start][end];
        }
        int result = INT_MAX;
        for (int k = start + 1; k <= end-1; k++) {
            int left = helper(start, k, cuts, dp);
            int right = helper(k, end, cuts, dp);
            int cost = cuts[end] - cuts[start] + left + right;
            result = min(result, cost);
        }
        dp[start][end] = (result == INT_MAX) ? 0 : result;
        return dp[start][end];
    }
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(), cuts.end());
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        int N=cuts.size();
        vector<vector<int>> dp(N, vector<int>(N, -1));
        return helper(0, N-1, cuts, dp);
    }
};