class Solution {
    bool compare(vector<int>&mp2,vector<int>&mp1){
        for(int i=0;i<52;i++){
            if(mp2[i]<mp1[i]){ return false ;}
        }
        return true;
    }
public:
    string minWindow(string s, string t) {
        unordered_set<char> isPresent;
        vector<int> mp1(52,0);
        vector<int> mp2(52,0);
        int n=s.length();
        int m=t.length();
        string ans="";

        for(int i=0;i<m;i++){
            int ind= t[i] -  ( (97<=t[i] && t[i]<=122) ? 97 : 39 );
            mp1[ind]++;
            isPresent.insert(t[i]);
        }

        int start=0;
        for(int i=0;i<n;i++){

          if( isPresent.find(s[i])==isPresent.end()){ continue; }

          int ind= s[i] -  ( (97<=s[i] && s[i]<=122) ? 97 : 39 );
          mp2[ind]++;

          if(compare(mp2,mp1)){

          while(start<=i && compare(mp2,mp1) ){
              if( isPresent.find(s[start]) !=isPresent.end()){
                  int ind= s[start] -  ( (97<=s[start] && s[start]<=122) ? 97 : 39 );
                  mp2[ind]--;}
              start++;
          }
          start--;
          string temp=s.substr(start,i-start+1);
          start++;
          if ( ans=="" || ans.size()>temp.size() ){ ans=temp;}
          
          }
        }
        return ans;
    }
};