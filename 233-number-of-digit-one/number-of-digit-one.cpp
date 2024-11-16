class Solution {
public:
    int getBaseValue(int n) {
        return pow(10,(to_string(n).size()) - 1);
    }
    int helper(int n) {
        if (n <= 0) {
            return 0;
        }
        if (n <= 9) {
            return 1;
        }
        int base=getBaseValue(n);
        int msb = n / base;
        if(((base*2)-1)>n){
            return msb * helper(base-1) + (n-base+1) + helper(n-msb*base);
        }
        return msb * helper(base-1) + base + helper(n-msb*base);
    }
    int countDigitOne(int n) { return helper(n); }
};