class Solution {
public:
    int getSum(int a, int b) {
        /*
         a | b | sum | carry
        ----------------------
         1 | 0 | 1  | 0
         0 | 1 | 1  | 0
         1 | 1 | 0  | 1
         0 | 0 | 0  | 0
        -----------------------
        the sum operation is only given by xor and we need to take care of carry ourselves
        */
        while(b){
            int carry=(a & b) << 1;
            a=a ^ b;
            b=carry;
        }
        return a;
    }
};