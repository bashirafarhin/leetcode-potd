class Solution {
public:
    int mod=1e9+7;
    int n;
    int target;
    vector<int>freq;
    vector<int>fact;
    vector<int>ifact;
    long long binaryExpo(int base, int exp){
        if(exp==0){
            return 1LL;
        }
        if(exp & 1){
            return base*binaryExpo(base,exp-1)%mod;
        } else {
            long long ans=binaryExpo(base,exp/2);
            return ans*ans%mod;
        }
    }

    int solve(int num, int oddSize, int sum, vector<vector<vector<int>>>&dp){
        if(num==10){
            if(oddSize==n/2 && sum==target){
                int evenSize=n-oddSize;
                return (1LL*fact[oddSize]*fact[evenSize])%mod;
            }
            return 0;
        }
        if(sum>target){
            return 0;
        }
        if(dp[num][oddSize][sum] !=-1){
            return dp[num][oddSize][sum];
        }
        int ans=0;
        for(int oddCount=0; oddCount<=min(freq[num],n/2-oddSize); oddCount++){
            int evenCount=freq[num]-oddCount;
            ans=(ans+((1LL*ifact[oddCount]*ifact[evenCount])%mod)*solve(num+1,oddSize+oddCount,sum+oddCount*num,dp))%mod;
        }
        return dp[num][oddSize][sum]=ans;
    }
    int countBalancedPermutations(string num) {
        n=num.size();
        int sum=accumulate(num.begin(),num.end(),0)-'0' * n;
        if(sum & 1){ return 0; }
        int evenplaces=n/2+n%2;
        int oddplaces=n/2;
        target=sum/2;
        freq.resize(10,0);
        fact.resize(n+1,1);
        ifact.resize(n+1,1);
        for(char n : num){
            freq[n-'0']++;
        }
        for(int i=1;i<=n;i++){
            fact[i]=(1LL*i*fact[i-1])%mod;
            ifact[i]=binaryExpo(fact[i],mod-2);
        }
        vector<vector<vector<int>>>dp(10+1,vector<vector<int>>(oddplaces+1,vector<int>(target+1,-1)));
        return solve(0,0,0,dp);
    }
};