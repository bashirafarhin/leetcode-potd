class Solution {
public:
    int mod=1e9+7;
    int helper(int l1,int l2,int i,vector<int>&nums,vector<vector<vector<int>>>&dp){
        if(i==nums.size()){
            return 1;
        }
        if(dp[l1][l2][i] !=-1){
            return dp[l1][l2][i];
        }
        int ans=0;
        int j=max(l1,nums[i]-l2);
        for(;j<=nums[i];j++){
            if(nums[i]-j<=l2){
                ans=(ans%mod+helper(j,nums[i]-j,i+1,nums,dp)%mod)%mod;
            } else {
                break;
            }
        }
        return dp[l1][l2][i]=ans;

    }
    int countOfPairs(vector<int>& nums) {
        vector<vector<vector<int>>>dp(50+1,vector<vector<int>>(50+1,vector<int>(2000,-1)));
        return helper(0,50,0,nums,dp);
    }
};