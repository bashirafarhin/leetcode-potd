class Solution {
int n;
int dp[1001];
int solveMem(int i, vector<int>& cost) {
    
    if(i >= n) {
        return 0;
    }
    
    if(dp[i] != -1) {
        return dp[i];
    }
    
    int a = cost[i] + solve(i+1, cost);
    int b = cost[i] + solve(i+2, cost);
    
    return dp[i] = min(a, b);
}
int solve(int i, vector<int>& cost) {
    
    if(i >= n) {
        return 0;
    }
    
    if(dp[i] != -1) {
        return dp[i];
    }
    
    int a = cost[i] + solve(i+1, cost);
    int b = cost[i] + solve(i+2, cost);
    
    return dp[i] = min(a, b);
}

public:
    int minCostClimbingStairs(vector<int>& cost) {
         n = cost.size();
    
    //Approach 1:- Memoization
    memset(dp, -1, sizeof(dp));
    
    int ans = min(solve(0, cost), solve(1, cost));
    
    return ans;  
    }
};