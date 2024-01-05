class Solution {

public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,0));

        for(int i=n-1;i>=0;i--){
            for(int prev=n-1; prev>=-1 ;prev--){
               if(i==n-1){
                 dp[i][prev+1]=(prev==-1 || nums[prev]<nums[i] ) ? 1 : 0 ;
                 continue;}
                 
                
                  int take=0;
                  if(prev==-1 || nums[prev]<nums[i]){
                   take=1+dp[i+1][i+1];
                   }
                  int nottake=dp[i+1][prev+1];
                  dp[i][prev+1]=max(take,nottake);  
                }
            
        }
       return dp[0][0];
    }
};