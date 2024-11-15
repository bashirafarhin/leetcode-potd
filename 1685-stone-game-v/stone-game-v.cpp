class Solution {
public:
    int helper(int s, int e, vector<int>& stoneValue, vector<int>& prefix, vector<vector<int>>&dp){
        if(s==e){
            return 0;
        }
        if(dp[s][e] !=-1){
            return dp[s][e];
        }
        int ans=0;
        for(int part=s;part<e;part++){
            int alice=0;
            int leftSum=prefix[part]-(s-1>=0 ? prefix[s-1] : 0);
            int rightSum=prefix[e]-prefix[part];
            if(leftSum<rightSum){
                alice=leftSum+helper(s,part,stoneValue,prefix,dp);
            }
            else if(leftSum>rightSum){
                alice=rightSum+helper(part+1,e,stoneValue,prefix,dp);
            } else {
                alice=max(leftSum+helper(s,part,stoneValue,prefix,dp),rightSum+helper(part+1,e,stoneValue,prefix,dp));
            }
            ans=max(ans,alice);
        }
        return dp[s][e]=ans;
    }
    int stoneGameV(vector<int>& stoneValue) {
        int n=stoneValue.size();
        vector<int>prefixSum(n,0);
        prefixSum[0]=stoneValue[0];
        for(int i=1;i<n;i++){
            prefixSum[i]=prefixSum[i-1]+stoneValue[i];
        }
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return helper(0,n-1,stoneValue,prefixSum,dp);
    }
};