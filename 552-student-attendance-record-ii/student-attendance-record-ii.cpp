 class Solution {
 public:
int checkRecord(int n) {
    const int M = 1000000007;
    vector< vector<long> > dp(2, vector<long>(3, 0));
    dp = {{1,1,0},{1,0,0}};
    for(int i = 1; i < n; ++i){
        vector< vector<long> > tmp(2, vector<long>(3, 0));
        tmp[0][0] = ((dp[0][0] + dp[0][1] + dp[0][2])%M);
        tmp[0][1] = dp[0][0]%M;
        tmp[0][2] = dp[0][1];
        tmp[1][0] = (((dp[0][0] + dp[0][1] + dp[0][2])%M + (dp[1][0] + dp[1][1] + dp[1][2])%M))%M;
        tmp[1][1] = dp[1][0]%M;
        tmp[1][2] = dp[1][1]%M;
        dp = tmp;
    }
    long res = 0;
    for(int A = 0; A < 2; ++A){
        for(int L = 0; L < 3; ++L){
            res += dp[A][L]%M;
        }
    }
    return res%M;
}
};