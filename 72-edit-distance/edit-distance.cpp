class Solution {
    int solve(int i1,int i2,string word1,string word2,vector<vector<int>>& dp){
        if(i1==word1.size() && i2==word2.size()){
            return 0;
        }
        if(i2==word2.size()){
            return word1.size()-i1;
        }
        if(i1==word1.size()){
            return word2.size()-i2;
        }
        if(dp[i1][i2] !=-1){return dp[i1][i2];}
        if(word1[i1]==word2[i2]){
            return dp[i1][i2]=solve(i1+1,i2+1,word1,word2,dp);
        }
        int insert= 1+solve(i1,i2+1,word1,word2,dp);
        int del= 1+solve(i1+1,i2,word1,word2,dp) ;
        int replace= 1+solve(i1+1,i2+1,word1,word2,dp);
        return dp[i1][i2]=min({insert,del,replace});
    }
public:
    int minDistance(string word1, string word2) {
        int size1=word1.size();
        int size2=word2.size();
        vector<vector<int>>dp(size1,vector<int>(size2,-1));
        return solve(0,0,word1,word2,dp);
    }
};