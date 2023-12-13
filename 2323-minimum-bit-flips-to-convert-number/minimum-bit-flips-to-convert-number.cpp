class Solution {
public:
    int minBitFlips(int start, int goal) {
      start=start ^ goal; //only same bits will gets converted into 0 and others to 1
      int count=0;
      while(start !=0){
          count++;
          start=start & (start-1);
      }
      return count;
    }
};