class Solution {
    int dp[2500];
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        fill(dp,dp+n,1);
        for(int i=0;i<n;i++){
            for(int prev=0;prev<i;prev++){
             if(nums[prev]<nums[i] && dp[prev]+1>dp[i]){
                 dp[i]=dp[prev]+1;
             }
            }
        }
        return *max_element(dp,dp+n);
    }
};