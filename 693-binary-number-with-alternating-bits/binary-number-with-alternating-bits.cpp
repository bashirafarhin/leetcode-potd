class Solution {
public:
    bool hasAlternatingBits(int n) {
     int flag=n & 1;
     while (n !=0 && flag==(n & 1)){
         flag=1-flag;
         n=n>>1;}
     return n==0; 
    }
};