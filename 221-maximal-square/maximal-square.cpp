class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int length=0;
        int row=matrix.size();
        int col=matrix[0].size();
        vector<vector<int>>dp(row,vector<int>(col,0));
        for(int r=row-1;r>=0;r--){
            for(int c=col-1;c>=0;c--){
                if( (r==row-1 || c==col-1) && matrix[r][c]=='1'){ dp[r][c]=1; }
                else if(matrix[r][c]=='1') {
                    dp[r][c]=1+min({ dp[r][c+1],dp[r+1][c+1],dp[r+1][c] });
                }
                if(dp[r][c]>length){ length=dp[r][c]; }
            }
        }
        return length*length;
    }
};