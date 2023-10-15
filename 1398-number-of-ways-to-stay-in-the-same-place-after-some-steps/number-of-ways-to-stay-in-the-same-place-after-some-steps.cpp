class Solution {
    const int MOD = 1e9 + 7;
    int dp[505][505];
public:
    int numWays(int steps, int arrLen) {
        dp[0][0] = 1;
        for (int s = 0; s < steps; ++s) {
            for (int i = 0; i < arrLen && dp[s][i]; ++i) {
                if (i) (dp[s+1][i-1] += dp[s][i]) %= MOD;
                (dp[s+1][i] += dp[s][i]) %= MOD;
                (dp[s+1][i+1] += dp[s][i]) %= MOD;
            }
        }
        return dp[steps][0];
    }
};