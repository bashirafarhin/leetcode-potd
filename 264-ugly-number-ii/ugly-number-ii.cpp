class Solution {
public:
    int nthUglyNumber(int n) {
        //we only have to take multiples of 2,3,5
        vector<int> dp(n,0);
        dp[0]=1;
        int p2=0;
        int p3=0;
        int p5=0;
        for(int i=1;i<n;i++){
            int twoMultiple=dp[p2]*2;
            int threeMultiple=dp[p3]*3;
            int fiveMultiple=dp[p5]*5;
            dp[i]=min({ twoMultiple, threeMultiple, fiveMultiple });

            if(dp[i]==twoMultiple){p2++;}
            if(dp[i]==threeMultiple){p3++;}
            if(dp[i]==fiveMultiple){p5++;}
           
            
        }
        return dp[n-1];
    }
};