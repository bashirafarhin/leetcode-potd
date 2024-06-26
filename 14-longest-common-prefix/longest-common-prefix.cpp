class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
      int n=strs.size();
      int l=strs[0].size();

      for(int i=0;i<l;i++){
        char curr=strs[0][i];
        for(int j=1;j<n;j++){
            if(i==strs[j].length() || curr !=strs[j][i]){ return strs[0].substr(0,i); }
        }
      }
      return strs[0];
    }
};