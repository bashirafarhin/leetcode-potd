class Solution {
  public:
    string customSortString(string order, string s) {
     unordered_map<char,int> freq;

     for(char c : s){ freq[c]++; }

     string ans="";
     for(char c : order){
         while(freq[c] !=0 ){ ans+=c; freq[c]--; }
     }

     for(char c : s){
         while(freq[c] !=0 ){ ans+=c; freq[c]--; }
     }
     return ans;     
    }
};