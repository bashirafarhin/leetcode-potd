class Solution {
public:
    bool isValid(string x){
     stack<char> s;
     for(int i=0;i<x.length();i++){
       if(x[i]=='('){ s.push(x[i]); }
       else if (!s.empty() && (x[i] == ')' && s.top() == '(')) { s.pop(); }
       else { return false; }      
     }
     return s.empty();
    }






    void solve(int n,string& s,vector<string>&ans){
        if(n==0){ 
            if(isValid(s)){ ans.push_back(s); }
            return;
        }
        s.push_back('(');
        solve(n-1,s,ans);
        s.pop_back();

        s.push_back(')');
        solve(n-1,s,ans);
        s.pop_back();

    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string s="";
        solve(2*n,s,ans);
        return ans;
    }
};