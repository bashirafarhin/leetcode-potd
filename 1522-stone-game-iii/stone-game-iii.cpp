class Solution {
public:
    int helper(int ind, vector<int>&stones, vector<int>&suffix, vector<int>&dp){
        if(ind==stones.size()){ return 0; }
        if(dp[ind] !=-1){ return dp[ind]; }
        int n=stones.size();
        int score=INT_MIN;
        int curr=0;
        for(int j=ind;j<min(ind+3,n);j++){
            curr+=stones[j];
            score=max(score,curr+suffix[j]-helper(j+1,stones,suffix,dp));
        }
        return dp[ind]=score;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        int n=stoneValue.size();
        vector<int>suffix(n,0);
        for(int i=n-2;i>=0;i--){
            suffix[i]=stoneValue[i+1]+suffix[i+1];
        }
        vector<int>dp(n,-1);
        int alice=helper(0,stoneValue,suffix,dp);
        int bob=accumulate(stoneValue.begin(),stoneValue.end(),0)-alice;
        int res=alice-bob;
        return res ? (res > 0 ? "Alice" : "Bob") : "Tie";
    }
};