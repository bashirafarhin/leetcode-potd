class Solution {
public:
    vector<int> getRow(int rowIndex) {
     vector<int> ans={1};
     for(int row=1;row<=rowIndex;row++){
         vector<int> r(row+1,0);
         r[0]=ans[0];
         for(int col=1;col<=row;col++){
          if(col==row){
             r[col]=ans[col-1];
          }
          else{
             r[col]=(ans[col-1]+ans[col]);  
          }
         }
         ans=r;
     }
     return ans;   
    }
};