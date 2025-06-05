class Solution {
public:
    int minDis(int i, int j, string& word1, string& word2, vector<vector<int>>&dp){
        if(i==word1.size() && j==word2.size()){ return 0; }
        if(j==word2.size()){
            return word1.size()-i;
        }
        if(i==word1.size()){
            return word2.size()-j;
        }
        if(dp[i][j] !=-1){
        return dp[i][j];
        }
        if(i==word1.size() || j==word2.size()){ return INT_MAX; }
        if(word1[i]==word2[j]){
            return dp[i][j]=minDis(i+1,j+1,word1,word2,dp);
        } else {
            return dp[i][j]=1+min({
                minDis(i,j+1,word1,word2,dp),
                minDis(i+1,j,word1,word2,dp),
                minDis(i+1,j+1,word1,word2,dp)
            });
        }
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>>dp(word1.size(),vector<int>(word2.size(),-1));
        return minDis(0,0,word1,word2,dp);
    }
};