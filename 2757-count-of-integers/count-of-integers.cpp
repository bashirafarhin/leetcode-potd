class Solution {
public:
    int mod=1e9+7;
    int dp[23][2][401];
    int helper(int ind, int tight, int sum, string& num, int min_sum, int max_sum){
        if(ind==num.size()){
            return min_sum<=sum && sum<=max_sum;
        }
        if(dp[ind][tight][sum] !=-1){
            return dp[ind][tight][sum];
        }
        int ans=0;
        int limit=tight ? num[ind]-'0': 9;
        for(int digit=0;digit<=limit;digit++){
            ans=(ans%mod+helper(ind+1,tight && (digit==limit),sum+digit,num,min_sum,max_sum)%mod)%mod;
        }
        return dp[ind][tight][sum]=ans;
    }
    int count(string num1, string num2, int min_sum, int max_sum) {
        memset(dp,-1,sizeof(dp));
        int right=helper(0,1,0,num2, min_sum, max_sum);
        memset(dp,-1,sizeof(dp));
        int left=helper(0,1,0,num1, min_sum, max_sum);
        int sumOfNum1=accumulate(num1.begin(),num1.end(),0)-'0'*num1.size();
        int add=(min_sum<=sumOfNum1 && sumOfNum1<=max_sum);
        return (right-left+add+mod)%mod;
    }
};