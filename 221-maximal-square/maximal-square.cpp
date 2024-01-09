class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int row=matrix.size();
        int col=matrix[0].size();
        int length=0;
        vector<vector<int>> dp(row,vector<int>(col,0));
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if( (i==0 || j==0 ) && (matrix[i][j]=='1') ){
                    dp[i][j]=1;}
                else if(matrix[i][j]=='1'){
                    dp[i][j]=1+min( { dp[i-1][j] , dp[i-1][j-1] ,dp[i][j-1] } );
                }
                length=max(length,dp[i][j]);
            }
        }
        return length*length;
    }
};