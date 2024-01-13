class Solution {
    int solve(int start,int end,vector<vector<int>>& dp){
        if (start>=end){return 0;}
        if(dp[start][end] !=-1){return dp[start][end];}
        int min_money=1e9;
        for(int guess=start;guess<=end;guess++){
            int left=solve(start,guess-1,dp);
            int right=solve(guess+1,end,dp);
            int money=max(left,right)+guess;
            min_money=min(min_money,money);
        }
        return dp[start][end]=min_money;
    }
public:
    int getMoneyAmount(int n) {
      vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
      return solve(1,n,dp);  
    }
};