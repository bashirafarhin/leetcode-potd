class Solution {
public:
    int nthUglyNumber(int n) {
        //observation--->uglyNumber * any of(2,3,5)=uglyNumber
        vector<int>dp(n+1,0);
        int p2=1,p3=1,p5=1;
        dp[1]=1;
 
        for(int i=2;i<=n;i++){
            int twoMultiple=dp[p2]*2;
            int threeMultiple=dp[p3]*3;
            int fiveMultiple=dp[p5]*5;

            dp[i]=min( {twoMultiple,threeMultiple,fiveMultiple} );
           
            if(dp[i]==twoMultiple){ p2++; }
            if(dp[i]==threeMultiple){ p3++; }
            if(dp[i]==fiveMultiple){ p5++; }
        }

        return dp[n];
    }
};