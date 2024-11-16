class Solution {
public:
    int getBitLength(int n) {
        int len = 1;
        int num = 2;
        while (num <= n) {
            num *= 2;
            len++;
        }
        return len;
    }

    int helper(int ind, int prevBit, int tight, int& n, vector<vector<vector<int>>>&dp){
        if(ind<0){
            return 1;
        }
        if(dp[ind][prevBit][tight] !=-1){
            return dp[ind][prevBit][tight];
        }
        int ans=0;
        int limit=tight ? ((n >> ind) & 1) : 1;
        for(int digit=0;digit<=limit;digit++){
            if(prevBit==1 && digit==1){ continue; }
            ans+=helper(ind-1, digit, tight && (digit==limit), n, dp);
        }
        return dp[ind][prevBit][tight]=ans;
    }
    int findIntegers(int n) {
        int bitLength = getBitLength(n);
        vector<vector<vector<int>>>dp(bitLength,vector<vector<int>>(2,vector<int>(2,-1)));
        return helper(bitLength-1,0,1,n,dp);
    }
};