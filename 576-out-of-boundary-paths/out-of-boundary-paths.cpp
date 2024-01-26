class Solution {
    int mod=1e9+7;
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>>dp(m,vector<vector<int>>(n,vector<int>(maxMove+2,0)));
        int ans=0;
        dp[startRow][startColumn][1]=1;
        for(int move=1;move<=maxMove;move++){
            for(int x=0;x<m;x++){
                for(int y=0;y<n;y++){
                    if(x==0) ans=( ans+dp[x][y][move] ) % mod; //boundary
                    if(x==m-1) ans=( ans+dp[x][y][move] ) % mod; //boundary
                    if(y==0) ans=( ans+dp[x][y][move] ) % mod; //boundary
                    if(y==n-1) ans=( ans+dp[x][y][move] ) % mod; //boundary
                    
                    dp[x][y][move+1]=( ( (x>0 ? dp[x-1][y][move] : 0) + //up
                                       (x<m-1 ? dp[x+1][y][move] : 0) ) % mod+ //down
                                       ( (y>0 ? dp[x][y-1][move] : 0) + //left
                                       (y<n-1 ? dp[x][y+1][move] : 0) ) % mod //right
                     ) % mod;
                }
            }
        }
        return ans % mod;
    }
};