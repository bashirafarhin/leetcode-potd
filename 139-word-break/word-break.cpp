class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
      unordered_map<string,int> dict;
      for(string str : wordDict){
          dict[str]=1;
      }
      int n=s.length();
      vector<int>dp(n+1,0);
      dp[n]=1; //base case

      for(int i=n-1;i>=0;i--){
          string word="";
          for(int j=i;j<n;j++){
            word+=s[j];
            if( dict.count(word) && dp[j+1] ) {
                dp[i]=true;
                break;}
          }
      }

      return dp[0];  
    }
};