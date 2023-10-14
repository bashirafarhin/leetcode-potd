class Solution {
    vector<vector<int>> dp;
    int n;

    int DFS(int index, int paidTime, vector<int>& cost, vector<int>& time)
    {
        if(index >= n)
            return paidTime >= 0 ? 0 : INT_MAX;

        // if paidTime >= n - index rest all remaining walls can be painted for free
        if(paidTime >= n - index)
            return 0;
        
        // second state is paidTime + n to handle negative values
        if(dp[index][paidTime + n] != -1)
            return dp[index][paidTime + n];

        // add time[index] for paid painter
        int paid = DFS(index + 1, paidTime + time[index], cost, time);
        if(paid != INT_MAX)
            paid += cost[index];

        // subtract 1 for free painter
        int free = DFS(index + 1, paidTime - 1, cost, time);

        return dp[index][paidTime + n] = min(paid, free);
    }   

public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        
        n = cost.size();
        dp = vector<vector<int>>(n, vector<int>(2 * n + 1, -1));
        return DFS(0, 0, cost, time);
    }
};