class Solution {
    int func(string s,unordered_map<string,int>&map,int index,vector<int> &dp){
        if(index>=s.size()){return 0;}
        if(dp[index]!=-1){return dp[index];}
        int count=0,ans=s.size();
        string currstr="";
        for(int i=index;i<s.length();i++){
            currstr.push_back(s[i]);
            if(map.find(currstr)==map.end()){
                count=currstr.length()+func(s,map,i+1,dp);
            }
            else{
                count=func(s,map,i+1,dp); 
            }
            ans=min(ans,count);
        }
        return dp[index]=ans;
    }
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_map<string,int> map;
        for(string word : dictionary){map[word]++;}
        vector<int> dp(s.size(),-1);
        return func(s,map,0,dp);
    }
};