class Solution {
public:
    int allPaths(int idx, vector<int>&nums, vector<int>&dp){
        if(idx>=nums.size()){
            return 0;
        }
        if(dp[idx] !=-1){
            return dp[idx];
        }
        int take=nums[idx]+allPaths(idx+2,nums,dp);
        int notTake=allPaths(idx+1,nums,dp);
        return dp[idx]=max(take, notTake);
    }
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        return allPaths(0,nums,dp);
    }
};