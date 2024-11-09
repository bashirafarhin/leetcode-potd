class Solution {
public:
    int helper(int start, int end, vector<int>&piles, vector<vector<int>>&dp){
        if(start>end){
            return 0;
        }
        if(dp[start][end] !=-1){ return dp[start][end]; }
        int pickFirst=piles[start]+min(helper(start+2,end,piles,dp),helper(start+1,end-1,piles,dp));
        int pickEnd=piles[end]+min(helper(start+1,end-1,piles,dp),helper(start,end-2,piles,dp));
        return dp[start][end]=max(pickFirst,pickEnd);
    }

    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        int score1=helper(0,n-1,piles,dp);
        int score2=accumulate(piles.begin(),piles.end(),0)-score1;
        return score1>score2;
    }
};