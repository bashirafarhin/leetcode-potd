class Solution {
public:
    int appendCharacters(string s, string t) {
      int len1=s.length();
      int len2=t.length();
      int i=0,j=0;
      while(i<len1 && j<len2){
        if(s[i]==t[j]){
            j++;
        }
        i++;
      }
      return i==len1 ? len2-j : 0 ;
    }
};