class Solution {
public:
    int solve(int i,string s,unordered_set<string>&dict,vector<int>&dp){
        int n=s.size();
        if(i==n){ return 0; }
        if(dp[i] !=-1){ return dp[i]; }
        string curr="";
        int ans=1e9,count=1e9;
        for(int j=i;j<n;j++){
         curr+=s[j];
         if(dict.find(curr)==dict.end()){
            count=curr.size()+solve(j+1,s,dict,dp);
         } else {
            count=solve(j+1,s,dict,dp);
         }
         ans=min(ans,count);
        }
       
        return dp[i]=ans;
    }

    int minExtraChar(string s, vector<string>& dictionary) {
        vector<int>dp(s.size(),-1);
        unordered_set<string>dict;
        for(string s : dictionary){ dict.insert(s); }
        return solve(0,s,dict,dp);
    }
};