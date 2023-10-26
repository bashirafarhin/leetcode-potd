class Solution {
    const int MOD = 1e9 + 7;
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(begin(arr), end(arr));
        int n = size(arr);
        vector<int> dp(n, 1);
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int l = 0, r = i-1;
            while (l <= r) {
                long long product = (long long)arr[l] * arr[r];
                if (product == arr[i]) {
                    dp[i] = (dp[i] + (l == r ? 1LL : 2LL) * dp[l] * dp[r]) % MOD;
                    ++l, --r;
                }
                else if (product < arr[i]) ++l;
                else --r;
            }
            ans = (ans + dp[i]) % MOD;
        }
        return ans;
    }
};