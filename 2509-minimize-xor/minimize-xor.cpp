class Solution {
public:
    int minimizeXor(int num1, int num2) {
       int bits=0;
       while(num2){
        num2=num2 & (num2-1);
        bits++;
       }
       int x=0;
       for(int i=31;i>=0 && bits>0;i--){
        if(num1 & (1<<i)){
            x = x | (1<<i);
            bits--;
        }
       }
       //use all bits of bits
       for(int i=0;i<32 && bits>0;i++){
        if(x & (1<<i)){ continue; }
        x = x | (1<<i);
        bits--;
       }
       return x;
    }
};