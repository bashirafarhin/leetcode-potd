class Solution {
public:
    int solve(int st,int end,vector<vector<int>>&dp){
        if(st>=end){ return 0; }
        if(dp[st][end] !=-1){ return dp[st][end]; }
        int ans=1e9;
        for(int guess=st;guess<=end;guess++){
            int l=solve(st,guess-1,dp)+guess;
            int r=solve(guess+1,end,dp)+guess;
            ans=min(max(l,r),ans);
        }
        return dp[st][end]=ans;
    }
    int getMoneyAmount(int n) {
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(1,n,dp);
    }
};