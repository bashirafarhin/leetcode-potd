class Solution {
public:
    bool hasAlternatingBits(int n) {
      int last_bit=n & 1;
      n=n>>1;
      int second_last_bit=n & 1;
      while(last_bit !=second_last_bit){
        last_bit=second_last_bit;
        n=n>>1;
        second_last_bit=n & 1;
      }
      return n==0;
    }
};