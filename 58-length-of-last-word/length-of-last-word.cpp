class Solution {
public:
    bool isEngChar(char ch){
      return  ('a'<=ch && ch<='z') || ('A'<=ch && ch<='Z') ? true : false ;
    }
    int lengthOfLastWord(string s) {
       int n=s.length();
       int wordAtIndexi=n;
       bool findchar=false;

       int i=n-1;
       for(;i>=0;i--){
        if(wordAtIndexi==n && isEngChar(s[i])){
            wordAtIndexi=i;}
        else if(s[i]==' ' && wordAtIndexi !=n ){ break; }
       }

       return wordAtIndexi-i;
    }
};