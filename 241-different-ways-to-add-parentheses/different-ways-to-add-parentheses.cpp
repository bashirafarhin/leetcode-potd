class Solution {
    vector<int> solve(string s,unordered_map<string,vector<int>>& dp){
         if(s.length()==2){
             int n=(s[0]-'0')*10+(s[1]-'0');
            return {n};}

        if(s.length()==1){
            int n=s[0]-'0';
            return {n};}

        if(dp.count(s)){return dp[s];}

        vector<int> ans;
        int n=s.length();
        for(int i=0;i<n;i++){
            if(s[i]=='+' || s[i]=='-' || s[i]=='*'){
                string left=s.substr(0,i);
                string right=s.substr(i+1);
                vector<int>l=solve(left,dp);
                vector<int>r=solve(right,dp);
                for(int val1 : l){
                    for(int val2 : r){
                        if(s[i]=='+'){ ans.push_back(val1+val2); }
                        else if(s[i]=='-'){ ans.push_back(val1-val2); }
                        else if(s[i]=='*'){ ans.push_back(val1*val2); }
                    }
                }
            }
        }
        return dp[s]=ans;
    }
public:
    vector<int> diffWaysToCompute(string expression) {
        unordered_map<string,vector<int>> dp;
        return solve(expression,dp);

    }
};