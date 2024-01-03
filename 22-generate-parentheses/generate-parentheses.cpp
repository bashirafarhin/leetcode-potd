class Solution {
    void solve(int open,int close,vector<string> &ans,string s,int n){
     if(open==n && close==n){
             ans.push_back(s);}

     if(open !=n){
         s+='(';
         solve(open+1,close,ans,s,n);
         s.pop_back();
     }
     if(open>close){
         s+=')';
         solve(open,close+1,ans,s,n);
         s.pop_back();
     }
     
     return;
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans; //to store answer
        solve(0,0,ans,"",n);
        return ans;
    }
};