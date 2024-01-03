class Solution {
    bool ispar(string x){
        stack<char> s;
         for(int i=0;i<x.length();i++){
           if(x[i]=='('){
            s.push(x[i]);
           }  else if (!s.empty() && (x[i] == ')' && s.top() == '(')) {
            s.pop();
            } else {
                return false; }
        }
    return s.empty();
    }


    void solve(int open,int close,vector<string> &ans,string s,int n){
     if(open==n && close==n){
         if(ispar(s)){ //check if isvalid parenthesis or not
             ans.push_back(s);}
         return ;
     }
     
     if(open !=n){
         s+='(';
         solve(open+1,close,ans,s,n);
         s.pop_back();
     }
     if(open !=0 && close !=n){
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