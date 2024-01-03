class Solution {
    int solve(string s,unordered_set<string>& dict,int i,vector<int>& dp){
        if(i==s.length()){return 0;}
        if(dp[i] !=-1){return dp[i];}
        int n=s.length();
        int minextrachar=n;
        string currWord="";
        for(int j=i;j<n;j++){
         currWord+=s[j];
         if(dict.find(currWord) != dict.end()){
            minextrachar=min( minextrachar , solve(s,dict,j+1,dp));
          } else {
            int val=currWord.length()+solve(s,dict,j+1,dp);
            minextrachar=min( minextrachar , val );}
          }

        return dp[i]=minextrachar;
        
    }
public:
    int minExtraChar(string s, vector<string>& dictionary) {
       unordered_set<string> dict;
       for(auto word : dictionary){
           dict.insert(word);
       }
       vector<int> dp(s.length(),-1);
       return solve(s,dict,0,dp); 
    }
};