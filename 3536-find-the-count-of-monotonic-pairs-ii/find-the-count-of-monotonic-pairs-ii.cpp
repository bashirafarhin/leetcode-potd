class Solution {
public:
    int mod = 1e9 + 7;
    int countOfPairs(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(1000 + 1, 0));

        for (int i = 0; i <= 1000; i++) {
            dp[n][i] = 1;
        }

        for (int i = n - 1; i >= 0; i--) {

            vector<int> prefix(1000 + 1, 0);
            prefix[0] = dp[i + 1][0];
            for (int j = 1; j <= 1000; j++) {
                prefix[j] = (prefix[j - 1] % mod + dp[i + 1][j] % mod) % mod;
            }
            for (int prev1 = 0; prev1 <= 1000; prev1++) {
                int prev2 = i == 0 ? nums[0] : nums[i - 1] - prev1;
                int left = max(prev1, nums[i] - prev2);
                int right = nums[i];
                if (left <= right) {
                    dp[i][prev1] = (prefix[right] - (left > 0 ? prefix[left - 1] : 0) + mod) % mod;
                } else {
                    dp[i][prev1] = 0;
                }
            }
        }

        return dp[0][0];
    }
};