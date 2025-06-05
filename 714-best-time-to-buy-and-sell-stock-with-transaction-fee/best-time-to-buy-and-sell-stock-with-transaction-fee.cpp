class Solution {
public:
// if buy -> sell or not sell
// if sell -> buy or not buy
    int maxP(int i, int buy, vector<int>& prices, int fee, vector<vector<int>>&dp){
        if(i==prices.size()){
            return 0;
        }
        if(dp[i][buy] !=-1){
            return dp[i][buy];
        }
        if(buy){
            return dp[i][buy]=max(prices[i]+maxP(i+1,0,prices,fee,dp),maxP(i+1,1,prices,fee,dp));
        }
        return dp[i][buy]=max(-prices[i]+maxP(i+1,1,prices,fee,dp)-fee,maxP(i+1,0,prices,fee,dp));
    }
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
        return maxP(0,0,prices,fee,dp);
    }
};