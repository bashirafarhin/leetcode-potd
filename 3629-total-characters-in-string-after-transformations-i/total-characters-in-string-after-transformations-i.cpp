class Solution {
public:
    int helper(string s, int t, vector<int>& dp) {
        int mod = 1e9 + 7;
        int ans = 0;
        if (s == "ab" && dp[t] != -1) {
            return dp[t];
        }
        for (int i = 0; i < s.length(); i++) {
            int lt = t;
            int moves = 'z' - s[i];
            if (moves >= lt) {
                ans++;
            } else {
                lt -= (moves + 1);
                string ss = "ab";
                ans = (ans % mod + helper(ss, lt, dp) % mod) % mod;
            }
        }
        return dp[t] = ans;
    }
    int lengthAfterTransformations(string s, int t) {
        vector<int> dp(1e5 + 1, -1);
        return helper(s, t, dp);
    }
};