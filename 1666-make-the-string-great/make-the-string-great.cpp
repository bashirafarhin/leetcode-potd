class Solution {
public:
    string makeGood(string s) {
      int n=s.length();
      string ans="";
      for(int i=0;i<n;i++){
        
        if(ans.size()>0 && (ans.back()==(s[i]+32) || ans.back()==(s[i]-32)) ){ ans.pop_back(); }

        else{ ans.push_back(s[i]); }
      }
      return ans;
    }
};