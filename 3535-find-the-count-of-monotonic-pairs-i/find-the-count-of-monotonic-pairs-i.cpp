class Solution {
public:
    int mod = 1e9 + 7;
    int helper(int prev1, int i, vector<int>& nums, vector<vector<int>>& dp) {
        if (i == nums.size()) {
            return 1;
        }
        if (dp[prev1][i] != -1) {
            return dp[prev1][i];
        }
        int ans = 0;
        int prev2 = i == 0 ? nums[0] : nums[i - 1] - prev1;
        for (int j = max(prev1, nums[i] - prev2); j <= nums[i]; j++) {
            if (nums[i] - j <= prev2) {
                ans = (ans % mod + helper(j, i + 1, nums, dp) % mod) % mod;
            } else {
                break;
            }
        }
        return dp[prev1][i] = ans;
    }
    int countOfPairs(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(50 + 1, vector<int>(n, -1));
        return helper(0, 0, nums, dp);
    }
};