class Solution {
public:
    //dry run to understand
    //why greedy is not working
    //why states of t is not taken, if u are choosing the same set of numbers ,the t will also be same
    int dfs(int m, int t, int k, vector<int>&dp) {
        if(dp[k] !=-1){
            return dp[k];
        }
        if (t <= 0) {
            return 0;
        }
        for (int i = 1; i <= m; i++) {
            if (!(k & (1 << i)) && !dfs(m, t - i, k | (1 << i), dp)) {
                return dp[k]=1;
            }
        }
        return dp[k]=0;
    }
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if (desiredTotal <= maxChoosableInteger) {
            return true;
        }
        int total = maxChoosableInteger * (maxChoosableInteger + 1) / 2;
        if (total < desiredTotal) {
            return false;
        } else if (total == desiredTotal) {
            return maxChoosableInteger % 2;
        }
        vector<int>dp(1<<20+1, -1);
        return dfs(maxChoosableInteger, desiredTotal, 0, dp);
    }
};