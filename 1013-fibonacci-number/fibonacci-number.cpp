class Solution {
public:
    int solve(int n,vector<int> &dp){
     if(n==0 || n==1){return n;}
     if(dp[n]==-1){
      dp[n]=(solve(n-1,dp)+solve(n-2,dp))%(1000000007);}
     return dp[n];
    }
    int fib(int n) {
     vector<int> dp(n+1,-1);
     return solve(n,dp);  
    }
};