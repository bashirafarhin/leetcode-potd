class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
      /*
      1-If any column in a 32 bit number is 0 then that column will remain 0
       for any number of bitwise and operation
      2-All column of rightside of the flipped bit is also flipped that means
       all columns of the rightside    of the flipped bit will remain 0
      3-Leftmost consecutive element in (left,right) range are always fixed in given range
      */
      int count=0;
      while(left !=right){
          left>>=1;
          right>>=1;
          count++;
      }
      return left<<count;  
    }
};