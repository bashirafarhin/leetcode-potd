class Solution {
public:
    vector<vector<int>> generate(int numRows) {
     vector<vector<int>> ans;
     vector<int> ro(1,1);
     ans.push_back(ro);
     for(int row=1;row<numRows;row++){
         vector<int> r(row+1,0);
         r[0]=ans[row-1][0];
         for(int col=1;col<=row;col++){
          if(col==row){
             r[col]=ans[row-1][col-1];
          }
          else{
             r[col]=ans[row-1][col-1]+ans[row-1][col];  
          }
         }
         ans.push_back(r);
     }
     return ans;
    }
};