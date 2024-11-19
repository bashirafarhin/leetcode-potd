class Solution {
public:
    int helper(int ind, int tight, int placed, string& nums, vector<string>& digits, vector<vector<vector<int>>>&dp) {
        if (ind == nums.size()) {
            return placed ? 1 : 0;
        }
        if(dp[ind][tight][placed] !=-1){
            return dp[ind][tight][placed];
        }
        int limit = tight ? nums[ind] - '0' : 9;
        int ans = 0;
        if (placed==0) {
            ans += helper(ind + 1, 0, placed, nums, digits, dp);
        }
        for (string digit : digits) {
            int d=stoi(digit);
            if (d <= limit) {
                ans += helper(ind + 1, tight && d == limit, 1, nums, digits, dp);
            }
        }
        return dp[ind][tight][placed]=ans;
    }
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        string nums = to_string(n);
        vector<vector<vector<int>>>dp(109+1,vector<vector<int>>(2,vector<int>(2,-1)));
        return helper(0, 1, 0, nums, digits, dp);
    }
};