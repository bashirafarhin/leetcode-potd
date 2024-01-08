class Solution {
    bool ispalindrome(string s){
        int i=0;
        int j=s.length()-1;
        while(i<j){
            if( s[i] !=s[j] ){return false;}
            i++;
            j--;
        }
        return true;
    }

    void solve(int i,string s,vector<string>& curr,vector<vector<string>>& ans){
     if(i==s.length()){
         ans.push_back(curr);
         return ;}
    
     int n=s.length();
     for(int j=i;j<n;j++){
        string var=s.substr(i,j-i+1);
        if(ispalindrome(var)){
         curr.push_back(var);
         solve(j+1,s,curr,ans);
         curr.pop_back();
        }
     }
     return ;
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> curr;
        solve(0,s,curr,ans);
        return ans;
    }
};