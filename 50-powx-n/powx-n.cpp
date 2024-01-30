class Solution {
public:
    double myPow(double x, long n) {
        if(n==0){ return 1; }
        if(n<0){ return 1/ ( myPow(x,-1*n) ); }
        if(n & 1){
            return x*myPow(x,n-1);
        }
        double val=myPow(x,n/2);
        return val*val;
    }
};