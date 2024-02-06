class Solution {
    bool compare(vector<int>&mp1,vector<int>&mp2){
      for(int i=0;i<256;i++){
         if(mp1[i]==0 && mp2[i]>0){ continue; }
         if(mp1[i]>mp2[i]){ return false; }
      }
      return true;
    }
public:
    string minWindow(string s, string t) {
        vector<int> mp1(256,0);
        vector<int> mp2(256,0);
        int n=s.length();
        int m=t.length();
        string ans="";

        for(int i=0;i<m;i++){ mp1[t[i]]++; }

        int start=0;
        for(int i=0;i<n;i++){
          mp2[s[i]]++;
          
          if( compare(mp1,mp2) ){
            while(start<=i && compare(mp1,mp2) ){
              mp2[s[start]]--;
              start++;
            }
            start--;
            string temp=s.substr(start,i-start+1);
            start++;
            if ( ans=="" || ans.size()>temp.size() ){ ans=temp; }
          }
         
        }

        return ans;
    }
};