class Solution {
    int solve(vector<int>&nums,int i,int prev,vector<vector<int>>&dp){
        if(i==nums.size()-1){
            return (prev==-1 || nums[prev]<nums[i] ) ?  1 : 0 ;
        }
        if(dp[i][prev+1] !=-1){return dp[i][prev+1];}
        int take=0;
        if(prev==-1 || nums[prev]<nums[i]){
            take=1+solve(nums,i+1,i,dp);
        }
        int nottake=solve(nums,i+1,prev,dp);
        return dp[i][prev+1]=max(take,nottake);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return solve(nums,0,-1,dp);
    }
};