class Solution {
public:
    int minSteps(vector<int>& nums, int i, vector<int>&dp){
        if(i>=nums.size()-1){
            return 0;
        }
        if(dp[i] !=-1){
            return dp[i];
        }
        int ans=INT_MAX;
        for(int range=nums[i]; range>0 ; range--){
            int next=minSteps(nums,i+range,dp);
            if(next != INT_MAX){
                next++;
            }
            ans=min(ans,next);
        }
        return dp[i]=ans;

    }
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        int ans =  minSteps(nums,0,dp);
        return ans == INT_MAX ? -1 : ans;
    }
};