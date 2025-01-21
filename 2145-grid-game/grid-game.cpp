class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int c=grid[0].size();
        long long totalSum=accumulate(grid[0].begin(),grid[0].end(),0LL);
        long long p1=grid[0][0];
        long long p2=grid[1][0];
        long long cost=totalSum-p1;
        for(int col=1;col<c;col++){
            p1+=grid[0][col];
            long long inBet=max(totalSum-p1,p2);
            cost=min(cost,inBet);
            p2+=grid[1][col];
        }
        return cost;
    }
};