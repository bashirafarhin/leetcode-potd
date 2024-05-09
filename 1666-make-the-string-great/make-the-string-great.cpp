class Solution {
public:
    string makeGood(string s) {
      int n=s.length();
      if(n<=1){ return s; }
      for(int i=0;i<n-1;i++){
        if( s[i]==(s[i+1]+32) || s[i]==(s[i+1]-32) ){
            string ns=s.substr(0,i)+s.substr(i+2);
            return makeGood(ns);
        }
      }
      return s;
    }
};