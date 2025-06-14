class Solution {
public:
    int maxP(vector<int>& prices, int i, int buy, vector<vector<int>>&dp){
        if(i==prices.size()){
            return 0;
        }
        if(dp[i][buy] !=-1){
            return dp[i][buy];
        }
        if(buy){
            return dp[i][buy]=max(-prices[i]+maxP(prices, i+1, 0, dp),maxP(prices, i+1, buy, dp));
        } else {
            return dp[i][buy]=max(prices[i]+maxP(prices, i, 1, dp),maxP(prices, i+1, buy, dp));
        }
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
        return maxP(prices, 0, 1, dp);
    }
};