class Solution {
public:
    int titleToNumber(string columnTitle) {
       int n=columnTitle.length();
       int cn=0;
       for(int i=0;i<n;i++){
           int r=columnTitle[i]-64;
           cn=r + cn * 26;        
       }
       return cn;
    }
};