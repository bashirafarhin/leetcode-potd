class Solution {
public:
    int helper(int ind, int M, vector<int>&piles, vector<vector<int>>&dp){
        if(ind==piles.size()){ return 0; }
        if(dp[ind][M] !=-1){ return dp[ind][M]; }
        int ans=0;
        int alice=0;
        int remaining=ind+2*M-1;
        int n=piles.size();
        for(int j=ind; j<=min(remaining,n-1); j++){
            alice+=piles[j];
            int remainingPiles=accumulate(piles.begin()+j+1,piles.end(),0);
            ans=max(ans,alice+remainingPiles-helper(j+1,max(M,(j-ind)+1),piles,dp));
        }
        return dp[ind][M]=ans;
    }
    int stoneGameII(vector<int>& piles) {
        int n=piles.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return helper(0,1,piles,dp);
    }
};