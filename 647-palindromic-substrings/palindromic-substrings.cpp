class Solution {
public:
    int countPalindrome(string& s,int start,int end){
        int count=0;
        while(start>=0 && end<s.length() && s[start]==s[end]){
            count++ ; start-- ; end++ ;
        }
        return count;
    }
    int countSubstrings(string s) {
      int n=s.length();
      int count=0;
      for(int i=0;i<n;i++){
       count+=countPalindrome(s,i,i)+countPalindrome(s,i,i+1); // even + odd length palindrome
      }
      return count;
    }
};