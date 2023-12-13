class Solution {
public:
    int hammingDistance(int x, int y) {
      x=x ^ y;
      int count=0;
      while(x !=0){
          count++;
          x=x & (x-1);
      }
      return count;
    }
};