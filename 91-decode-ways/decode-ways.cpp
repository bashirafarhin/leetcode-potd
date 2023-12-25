class Solution {
    int recur(int i,string s,vector<int>&dp){
        if(s[i]=='0'){return 0;}
        if(i>=s.length()-1){return 1;}
        if(dp[i] !=-1){return dp[i];}
        int ans1=recur(i+1,s,dp);
        int ans2=0;
        int num=(s[i]-'0')*10+(s[i+1]-'0');
        if(num>0 && num<27)
         {ans2=recur(i+2,s,dp);}
         dp[i]=ans1+ans2;
        return ans1+ans2;
    }
public:
    int numDecodings(string s) {
      vector<int>dp(s.length(),-1);
      return recur(0,s,dp);  
    }
};