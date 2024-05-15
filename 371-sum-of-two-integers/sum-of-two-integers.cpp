class Solution {
public:
    int getSum(int a, int b) {
        //negative numbers adjust themselves so work only using positve numbers examples
        int ans=0;
        while(b){
            int carry=(a & b)<<1;
            a=a^b;
            b=carry;
        }
        return a;
    }
};