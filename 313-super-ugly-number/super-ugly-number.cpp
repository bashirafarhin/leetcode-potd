class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> dp(n,0);
        dp[0]=1;
        vector<int> p(primes.size(),0);
        for(int i=1;i<n;i++){

           long long int ans=INT_MAX;
           for(int j=0;j<primes.size();j++){
              ans = min ( ans , 1LL*dp[p[j]]*primes[j]  ) ;
           }
           
           dp[i]=int(ans);

           for(int j=0;j<primes.size();j++){
              if( (dp[i] % primes[j])==0 ){
                  p[j]++;
                  }
           }
            
        }

        return dp[n-1];
    }
};