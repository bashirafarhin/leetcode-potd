class Solution {
public:
    int bitwiseComplement(int num) {
     if(num==0) return 1;
     if(num==1) return 0;
     int n=num;
     int mask=0;
     while(n !=0){
         n>>=1;
         mask<<=1;
         mask=mask | 1;
         
     }
     return (~num) &mask;   
    }
};