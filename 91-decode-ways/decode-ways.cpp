class Solution {
    int recur(int i,string s,vector<int>&dp){
        if(s[i]=='0'){return 0;}
        if(i==s.length()){return 1;}
        if(dp[i] !=-1){return dp[i];}
        dp[i]=recur(i+1,s,dp);
        if(i+1<s.length() && (s[i]=='1' || s[i]=='2' && s[i+1]<='6'))
         {dp[i]+=recur(i+2,s,dp);}
        return dp[i];
    }
public:
    int numDecodings(string s) {
      vector<int>dp(s.length(),-1);
      return recur(0,s,dp);  
    }
};