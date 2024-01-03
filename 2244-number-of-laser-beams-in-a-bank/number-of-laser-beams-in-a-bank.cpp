class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
      int laserbeams=0;
      int n=bank.size();
      int prevlaser=0;
      for(int row=0;row<n;row++){
       int m=bank[row].size();
       int currlaser=0;
       for(int col=0;col<m;col++){
           if(bank[row][col]=='1'){currlaser++;}}
         if(prevlaser !=0){
             laserbeams+=(prevlaser*currlaser);}
         if(currlaser !=0) {prevlaser=currlaser;}
        
       }
       return laserbeams;
    }
};