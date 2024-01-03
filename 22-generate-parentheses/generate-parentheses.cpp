class Solution {
     bool ispar(string x){
        
        stack<char> s;
    for(int i=0;i<x.length();i++)
    {
        if(x[i]=='(')
        {
            s.push(x[i]);
        }
         else if (!s.empty() && (x[i] == ')' && s.top() == '(')) {
            s.pop();
            }
            else {
                return false;
                
            }
                
    }
    return s.empty();
    }


    void solve(int l,int r,vector<string> &arr,string s,int n){
     if(l==0 && r==0){
         if(ispar(s)){
             arr.push_back(s);
             }
         return ;
     }
     if(l !=0){
         s+='(';
         solve(l-1,r,arr,s,n);
         s.pop_back();
     }
     if(l !=n && r !=0){
         s+=')';
         solve(l,r-1,arr,s,n);
         s.pop_back();
     }
     
     return;
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> arr;
        solve(n,n,arr,"",n);
        return arr;
    }
};