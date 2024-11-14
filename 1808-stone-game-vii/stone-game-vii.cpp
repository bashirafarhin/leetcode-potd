class Solution {
public:
    int helper(int s, int e, int totalSum, vector<int>& stones, vector<vector<int>>&dp) {
        if (s >= e) {
            return 0;
        }
        if(dp[s][e] !=-1){ return dp[s][e]; }
        return dp[s][e]=max(totalSum - stones[s] - helper(s + 1, e, totalSum - stones[s], stones, dp),
                   totalSum - stones[e] - helper(s, e-1 , totalSum - stones[e], stones, dp));
    }
    int stoneGameVII(vector<int>& stones) {
        int n = stones.size();
        int ans = INT_MAX;
        int totalSum=accumulate(stones.begin(),stones.end(),0);
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return helper(0, n - 1, totalSum, stones, dp);
    }
};