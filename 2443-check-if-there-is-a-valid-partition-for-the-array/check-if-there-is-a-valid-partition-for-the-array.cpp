class Solution {
public:
    bool solve(vector<int> &nums,int i,int n,vector<int> &dp){
     if(i==n){return true;}
     if(dp[i]==-1){
     bool a=false,b=false,c=false;
     if(i+1<n && nums[i]==nums[i+1])
      { a=solve(nums,i+2,n,dp);}
     if(!a && i+2<n && nums[i]==nums[i+1] && nums[i]==nums[i+2])
      { b=solve(nums,i+3,n,dp);}
     if(!b && i+2<n && nums[i]==nums[i+1]-1 && nums[i+1]==nums[i+2]-1)
      { c=solve(nums,i+3,n,dp);}
     dp[i]=a || b || c;}
     return dp[i];
    }
    bool validPartition(vector<int>& nums) {
     int n=nums.size();
     vector<int> dp(n,-1);
     return solve(nums,0,n,dp);
    }
};