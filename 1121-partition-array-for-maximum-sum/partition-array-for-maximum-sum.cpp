class Solution {
public:
    int solve(vector<int>& arr, int i, int k, vector<int>& dp) {
        if (i == arr.size()) {
            return 0;
        }
        if (dp[i] != -1) {
            return dp[i];
        }
        int n = arr.size();
        int ans = 0;
        int maxi = 0;
        for (int j = i; j < min(n, i + k); j++) {
            maxi = max(maxi, arr[j]);
            ans = max(ans, maxi * (j - i + 1) + solve(arr, j + 1, k, dp));
        }
        return dp[i] = ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int> dp(arr.size(), -1);
        return solve(arr, 0, k, dp);
    }
};