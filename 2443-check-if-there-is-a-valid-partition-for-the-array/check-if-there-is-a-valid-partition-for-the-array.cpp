class Solution {
public:
 
    bool validPartition(vector<int>& nums) {
     int n=nums.size();
     vector<bool> dp(n+1,true);
     for(int i=n-1;i>=0;i--){
       bool a=false,b=false,c=false;
       if(i+1<n && nums[i]==nums[i+1])
          { a=dp[i+2];}
       if(!a && i+2<n && nums[i]==nums[i+1] && nums[i]==nums[i+2])
          { b=dp[i+3];}
       if(!b && i+2<n && nums[i]==nums[i+1]-1 && nums[i+1]==nums[i+2]-1)
          { c=dp[i+3];}
        dp[i]=a || b || c;}
     return dp[0];
    }
};