class Solution {
public:
    int helper(int ind, vector<int>&prefix, vector<int>&dp){
        if(ind==prefix.size()-1){
            return prefix[prefix.size()-1];
        }
        if(dp[ind] != INT_MIN){
            return dp[ind];
        }
        return dp[ind]=max(helper(ind+1,prefix,dp),prefix[ind]-helper(ind+1,prefix,dp));
    }
    int stoneGameVIII(vector<int>& stones) {
        int n=stones.size();
        vector<int>prefixSum(n,0);
        prefixSum[0]=stones[0];
        for(int i=1;i<n;i++){
            prefixSum[i]=prefixSum[i-1]+stones[i];
        }
        vector<int>dp(n,INT_MIN);
        return helper(1, prefixSum, dp);
    }
};