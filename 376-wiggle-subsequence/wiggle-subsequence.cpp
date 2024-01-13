class Solution {
public:
    int solve(int i,int inc,vector<int>& nums,vector<vector<int>>&dp){
        if(i==nums.size()-1){
            return 1;
        }
        if(dp[i][inc] !=-1){return dp[i][inc];}
        int take=0;
        if(inc==1 && nums[i]<nums[i+1]){    
            take=1+solve(i+1,0,nums,dp);
        }
        if(inc==0 && nums[i]>nums[i+1]){    
            take=1+solve(i+1,1,nums,dp);
        }        
        int nottake=solve(i+1,inc,nums,dp);
        return dp[i][inc]=max(take,nottake);
    }
    int wiggleMaxLength(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int>(2,-1));
        return max( solve(0,0,nums,dp),solve(0,1,nums,dp) );
    }
};