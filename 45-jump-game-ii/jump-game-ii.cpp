class Solution {
    int solve(vector<int>&nums,int i,vector<int>& dp){
        if(i>=nums.size()-1){
            return 0;}
        if(dp[i] !=-1){return dp[i];}
        int range=nums[i];
        int ans=1e9;
        for(int j=range;j>=1;j--){
         
            ans= min( ans , 1+ solve(nums,i+j,dp));
        }
        return dp[i]=ans;
    }
public:
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return  solve(nums,0,dp);
    }
};