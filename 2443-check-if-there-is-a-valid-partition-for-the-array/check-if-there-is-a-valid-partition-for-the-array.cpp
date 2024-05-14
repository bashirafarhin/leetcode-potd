class Solution {
public:
    bool solve(vector<int>&nums,int i,vector<int>&dp){
        if(i==nums.size()){
            return true;
        }
        if(dp[i] !=-1){
            return dp[i];
        }
        int n=nums.size();
        if(i+1<n && nums[i]==nums[i+1]){
            if(solve(nums,i+2,dp)){ return dp[i]=true; }
        }
        if(i+2<n && nums[i]==nums[i+1] && nums[i+1]==nums[i+2]){
            if(solve(nums,i+3,dp)){ return dp[i]=true; }
        }
        if(i+2<n && nums[i]+1==nums[i+1] && nums[i+1]+1==nums[i+2]){
            if(solve(nums,i+3,dp)){ return dp[i]=true; }
        }
        return dp[i]=false;        
    }

    bool validPartition(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        return solve(nums,0,dp);
    }
};