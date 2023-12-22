class Solution {
public:
    int maxScore(string s) {
      int n=s.length();
      int count1=0;
      int count0=0;
      for(int i=0;i<n;i++){
          if(s[i]=='1'){count1++;}}

      int ans=0;
      for(int i=0;i<n-1;i++){
          if(s[i]=='0'){count0++;}
          else {count1--;}
          ans=max(ans,count1+count0);
      }
      return ans;
    }
};