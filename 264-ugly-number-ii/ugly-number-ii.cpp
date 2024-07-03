class Solution {
public:
    int nthUglyNumber(int n) {
        int p2=0;
        int p3=0;
        int p5=0;
        vector<int>dp(n,0);
        dp[0]=1;
        for(int i=1;i<n;i++){
            int twoMultiple=2*dp[p2];
            int threeMultiple=3*dp[p3];
            int fiveMultiple=5*dp[p5];
            dp[i]=min({ twoMultiple,threeMultiple,fiveMultiple });

            if(twoMultiple==dp[i]){ p2++; }
            if(threeMultiple==dp[i]){ p3++; }
            if(fiveMultiple==dp[i]){ p5++; }
        }
        return dp[n-1];
    }
};