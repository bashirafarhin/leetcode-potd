class Solution {
    int mod=1e9+7;
    int solve(int Row,int Col,int maxMove,int r,int c,vector<vector<vector<int>>>&dp){
        if(r==Row || c==Col || r<0 || c<0){return 1;}
        if(maxMove==0){return 0;}
        if(dp[r][c][maxMove] !=-1){return dp[r][c][maxMove];}
        long long int left=solve(Row,Col,maxMove-1,r,c-1,dp)%(mod);
        long long int up=solve(Row,Col,maxMove-1,r-1,c,dp)%(mod);
        long long int right=solve(Row,Col,maxMove-1,r,c+1,dp)%(mod);
        long long int down=solve(Row,Col,maxMove-1,r+1,c,dp)%(mod);
        long long int a=(left+up+right+down) %mod;
        return dp[r][c][maxMove]=a;
    }
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>>dp(m,vector<vector<int>>(n,vector<int>(maxMove+1,-1)));
        return solve(m,n,maxMove,startRow,startColumn,dp);
    }
};