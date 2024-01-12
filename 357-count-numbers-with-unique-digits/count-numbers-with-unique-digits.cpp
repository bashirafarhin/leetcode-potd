class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
     if(n==0){return 1;}
     int ans=10;
     int curr=9;
     int opt=9;
     while(n >1 ){
         curr=curr*opt;
         opt--;
         n--;
         ans+=curr;
     }
     return ans;
    }
};