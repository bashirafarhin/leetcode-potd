class Solution {
public:
// recursion-TC O(3^n)
// dp-TC O(min(arrLen,steps)*steps)
    int m = 1e9 + 7;
    int helper(int i, int steps, int arrLen, vector<vector<int>>& dp) {
        if (steps == 0) {
            if (i == 0) {
                return 1;
            }
            return 0;
        }
        if (i < 0 || i == arrLen) {
            return 0;
        }
        if (dp[steps][i] != -1) {
            return dp[steps][i];
        }
        return dp[steps][i] = ((helper(i - 1, steps - 1, arrLen, dp)%m +
                               helper(i, steps - 1, arrLen, dp)%m)%m +
                               helper(i + 1, steps - 1, arrLen, dp)%m)%m ;
    }
    int numWays(int steps, int arrLen) {
        arrLen=min(arrLen,steps);
        vector<vector<int>> dp(steps + 1, vector<int>(arrLen + 1, -1));
        return helper(0, steps, arrLen, dp);
    }
};