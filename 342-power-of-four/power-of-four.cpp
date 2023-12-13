class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n <= 0)
            return false;
        if (n == 1)
            return true;
       float x=log (n)/log (4);
       return x==(int)x;


    }
};