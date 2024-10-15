class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==divisor){
            return 1;
        }
        bool pos = (dividend<=0 == divisor<0);
        unsigned int dd=abs(dividend);
        unsigned int dr=abs(divisor);
        unsigned int ans=0;
        while(dd>=dr){
            int currQ=0;
            int currDr=dr;
            while(dd>(dr<<(currQ+1))){
                currQ++;
            }
            ans+=(1<<currQ);
            dd-=(dr<<currQ);
        }
        if(ans==(1<<31) && pos){
            return INT_MAX;
        }
        return pos ? ans : -ans;

    }
};