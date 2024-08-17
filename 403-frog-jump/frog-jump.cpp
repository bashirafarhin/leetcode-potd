class Solution {
public:
    int helper(int i,int k,vector<int>& stones,unordered_map<int,int>& mp,vector<vector<int>>&dp){
        if(i>=stones.size()-1){
            return true;
        }
        if(dp[i][k] !=-1){
            return dp[i][k];
        }
        for(int j=k-1;j<=k+1;j++){
            if(j<=0){
                continue;
            }
            int nextStone=stones[i]+j;
            if(mp.find(nextStone) !=mp.end()){
                if(helper(mp[nextStone],j,stones,mp,dp)){
                    return dp[i][k]=1;
                }
            }
        }
        return dp[i][k]=0;
    }

    bool canCross(vector<int>& stones) {
       if(stones[1]>=2){
        return false;
       }
       unordered_map<int,int>mp;
       for(int i=0;i<stones.size();i++){
        mp[stones[i]]=i;
       }
       
       int n=stones.size();
       vector<vector<int>>dp(n,vector<int>(n,-1));
       return helper(0,0,stones,mp,dp); 
    }
};