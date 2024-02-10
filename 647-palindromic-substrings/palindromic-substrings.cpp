class Solution {
public:
    int isPalindrome(string& s,int start,int end,vector<vector<int>>&dp){
        if(start>end){ return 1; }
        if(dp[start][end] !=-1){ return dp[start][end];}
        return dp[start][end]=(s[start]==s[end]) ? isPalindrome(s,start+1,end-1,dp) : 0 ;
    }
    int countSubstrings(string s) {
      int n=s.length();
      int count=0;
      vector<vector<int>>dp(n,vector<int>(n,-1));
      for(int i=0;i<n;i++){
       for(int j=i;j<n;j++){
           if(isPalindrome(s,i,j,dp)){ count++; }
       }
      }
      return count;
    }
};