class Solution {
public:
    void solve(string s,int i,vector<string>&curr,vector<vector<string>>&ans){
        if(i==s.length()){
            ans.push_back(curr);
            return;
        }
        int n=s.length();
        for(int j=i;j<n;j++){
            int st=i;
            int end=j;
            while(st<=end && s[st]==s[end]){ st++; end--; }
            if(st>end){
                curr.push_back(s.substr(i,j-i+1));
                solve(s,j+1,curr,ans);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>curr;
        solve(s,0,curr,ans);
        return ans;
    }
};