class Solution {
public:
    int minimizeXor(int num1, int num2) {
     int setbits=0;
     while(num2){
       num2=num2 & (num2-1); setbits++;}
     int ans=0;
     for(int i=31;i>=0 && setbits;i--){
         if(num1 & (1<<i)){ans=ans | (1<<i);setbits--;}
     }
     for(int i=0;i<32 && setbits;i++){
         if(!(num1 & (1<<i)) ){ans=ans | (1<<i);setbits--;}
     }
     return ans;
    }
};