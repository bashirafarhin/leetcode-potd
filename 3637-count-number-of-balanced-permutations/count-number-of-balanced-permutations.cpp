class Solution {
public:
    int mod=1e9+7;
    int n;
    vector<int>freq;
    vector<int>fact;
    vector<int>ifact;

    long long binaryExpo(int base, int exp){
        if(exp==0){ return 1; }
        if(exp & 1){
            return base*binaryExpo(base,exp-1)%mod;
        } else {
            long long ans=binaryExpo(base,exp/2);
            return (ans * ans)%mod;
        }
    }

    void precomputeFactorials(int n){
        fact.resize(n+1,1);
        ifact.resize(n+1,1);
        for(int i=1;i<=n;i++){
            fact[i]=(1LL*i*fact[i-1])%mod;
            ifact[i]=binaryExpo(fact[i],mod-2);
        }
        return ;
    }

    int helper(int val, int target, int oddplaces, int evenplaces, vector<vector<vector<int>>>&dp){
        if(val==10){
            if(target==0 && oddplaces==0){
                return (1LL*fact[n-evenplaces]*fact[evenplaces])%mod;
            }
            return 0;
        }
        if(target<0){
            return 0;
        }
        if(dp[val][target][oddplaces] !=-1){ return dp[val][target][oddplaces]; }
        int ans=0;
        for(int count=0;count<=min(freq[val],oddplaces);count++){
            ans=(ans+(1LL*ifact[count]*ifact[freq[val]-count]%mod)*helper(val+1,target-val*count,oddplaces-count,evenplaces,dp))%mod;
        }
        return dp[val][target][oddplaces]=ans;
    }
    int countBalancedPermutations(string num) {
        n=num.size();
        int sum=accumulate(num.begin(),num.end(),0)-'0' * n;
        if(sum & 1){ return 0; }

        int evenplaces=(n+1)/2;
        int oddplaces=n/2;
        int target=sum/2;
        freq.resize(10,0);
        for(char n : num){
            freq[n-'0']++;
        }
        precomputeFactorials(n);
        vector<vector<vector<int>>>dp(10,vector<vector<int>>(target+1,vector<int>(oddplaces+1,-1)));
        return helper(0,target, oddplaces, evenplaces, dp);
    }
};