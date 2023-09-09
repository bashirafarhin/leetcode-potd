class Solution {
public:
int help(vector<int> nums, int t,vector<int> &dp)
{
    if(t<0)
    return 0;
    if(t==0)
    return 1;
    if(dp[t]!=-1)
    return dp[t];

    int res =0;
    for(auto x:nums)
    res += help(nums,t-x,dp);
    
    
    return dp[t] = res;
}
    int combinationSum4(vector<int>& nums, int target) {
       vector<int> dp(target+1,-1);
       return help(nums,target,dp);  
    }
};