class Solution {
public:
    int mod = 1e9 + 7;
    int solve(int n, int k, int target, vector<vector<int>>& dp) {
        if (target == 0 && n==0) {
            return 1;
        }
        if (n == 0) {
            return 0;
        }
        if (dp[n][target] != -1) {
            return dp[n][target];
        }

        int ans = 0;
        for (int i = 1; i <= k; i++) {
            if (target < i) {
                break;
            }
            ans=(ans%mod) + (solve(n - 1, k, target - i, dp)% mod);
        }
        return dp[n][target] = ans%mod;
    }

    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
        return solve(n, k, target, dp);
    }
};