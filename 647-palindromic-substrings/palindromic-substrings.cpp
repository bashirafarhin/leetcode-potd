class Solution {
public:
    int countSubstrings(string s) {
      int n=s.length();
      int count=0;
      for(int i=0;i<n;i++){
          for(int j=i;j<n;j++){
              int start=i;
              int end=j;
              while(end>start){
                  if(s[start] !=s[end]){ break; }
                  start++ ; end--;
              }
              if(start>=end){ count++; }
          }
      }
      return count;
    }
};