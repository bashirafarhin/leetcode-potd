class Solution {
public:
    int isPalindrome(string& s,int start,int end){
        if(start>end){ return 1; }
        return (s[start]==s[end]) ? isPalindrome(s,start+1,end-1) : 0 ;
    }
    int countSubstrings(string s) {
      int n=s.length();
      int count=0;
      for(int i=0;i<n;i++){
       for(int j=i;j<n;j++){
           if(isPalindrome(s,i,j)){ count++; }
       }
      }
      return count;
    }
};