class Solution {
public:
    int findComplement(int num) {
        int mask=0,n=num;
        while(n){
            mask<<=1;
            mask|=1;
            n>>=1;
        }
        return ~num & mask;
    }
};