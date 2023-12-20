class Solution {
public:
    int minFlips(int a, int b, int c) {
     int flips=0;
     while(c !=0 || a !=0 || b !=0){
      int la=a & 1;
      int lb=b & 1;
      int lc=c & 1;
      if(lc==1 && la==0 && lb==0 ){flips++;}
      else if(lc==0){
          if(la==1 && lb==1){flips+=2;}
          else if(la==1 || lb==1){flips++;}
      }
      a>>=1;
      b>>=1;
      c>>=1;
     }
     return flips;
    }
};