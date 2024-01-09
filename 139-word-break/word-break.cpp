class Solution {
    bool solve(int i,string s,unordered_map<string,int>& dict,vector<int>& dp){
        if(i==s.length()){return true;}
        if(dp[i] !=-1){return dp[i];}
        int n=s.length();
        string word="";
        for(int j=i;j<n;j++){
          word+=s[j];
          if(dict.count(word)){
              if( solve(j+1,s,dict,dp) ) {return dp[i]=true;}
          }

        }
        return dp[i]=false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
      unordered_map<string,int> dict;
      for(string str : wordDict){
          dict[str]=1;
      }
      int n=s.length();
      vector<int>dp(n,-1);
      return solve(0,s,dict,dp);  
    }
};