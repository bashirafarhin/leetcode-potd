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


    void solve(int open,int close,vector<string> &arr,string s,int n,vector<vector<int>>& dp){
     if(open==0 && close==0){
         if(ispar(s)){ //check if isvalid parenthesis or not
             arr.push_back(s);}
         return ;
     }
     
     if(open !=0){
         s+='(';
         solve(open-1,close,arr,s,n,dp);
         s.pop_back();
     }
     if(open !=n && close !=0){
         s+=')';
         solve(open,close-1,arr,s,n,dp);
         s.pop_back();
     }
     
     return;
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> arr;
        vector<vector<int>> dp(n,vector<int>(n,-1));
        solve(n,n,arr,"",n,dp);
        return arr;
    }
};