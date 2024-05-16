class Solution {
public:
    int solve(vector<int>& nums, int i, int target,vector<vector<int>>&dp) {
        if (i == nums.size()) {
            return target==0;
        }
        if(dp[i][target] !=-1){ return dp[i][target];}
        int take=0;
        if(nums[i]<=target){
         take = solve(nums, i + 1, target - nums[i],dp);
        }
        int nottake = solve(nums, i + 1, target,dp);
        return dp[i][target]=take+nottake;
    }

//watch DP 18 of striver
    int findTargetSumWays(vector<int>& nums, int target) {
      int n=nums.size();
      int sum=accumulate(nums.begin(),nums.end(),0);
      int t=(target+sum)/2;
      if(t<0 || (target+sum)%2==1)
      {return 0;}
      vector<vector<int>> dp(n , vector<int> (t+1, -1));
      return solve(nums,0,t,dp);
    }
};