class Solution {
    void recur(string s,int i,vector<string>&ans){
        if(i==s.length()){
            ans.push_back(s);
            return ;}
        if(isupper(s[i])){
            s[i]=tolower(s[i]);
            recur(s,i+1,ans);
            s[i]=toupper(s[i]);
        }
        recur(s,i+1,ans);
        if(islower(s[i])){
            s[i]=toupper(s[i]);
            recur(s,i+1,ans);
            s[i]=tolower(s[i]);
        }
        return ;
    }
public:
    vector<string> letterCasePermutation(string s) {
    vector<string> ans;
    recur(s,0,ans);
    return ans;
    }
};