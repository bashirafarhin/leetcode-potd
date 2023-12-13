class Solution {
public:
    int bitwiseComplement(int num) {
     int pos=0,i=0;
     int n=num;
     while(n !=0){
         if(n & 1){pos=i;}
         i++;n>>=1;
     }
     int result=0;
     i=0;
     while(pos>=0){
     if(!(num & 1)){result+=1<<i;}
     num>>=1;
     i++;
     pos--;}
     return result;   
    }
};