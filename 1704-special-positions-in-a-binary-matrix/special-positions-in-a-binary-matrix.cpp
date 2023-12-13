class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
      //brute force
      int pos=0;
      int row=mat.size();
      int col=mat[0].size();
      for(int i=0;i<row;i++){
       for(int j=0;j<col;j++){
           if(mat[i][j]==0){continue;}

             bool flag=true;
             for(int c=0;c<col;c++){
                 if(mat[i][c]==1 && j !=c){
                     flag=false;break;}}

             if(flag==true){
              for(int r=0;r<row;r++){
                 if(mat[r][j]==1 && i !=r){
                     flag=false;break;}}}
             if(flag==true){pos++;}       
       }
      }
      return pos;
    }
};