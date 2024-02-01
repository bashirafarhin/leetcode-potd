class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>ans;
        int row=matrix.size()-1;
        int col=matrix[0].size()-1;
        int r=0;
        int c=0;
        while( row>=r && col>=c){

            for(int i=c;i<=col;i++){
                ans.push_back(matrix[r][i]);
            }
            r++; //move to next row //shrinking the matrix
            
            for(int i=r;i<=row;i++){
                ans.push_back(matrix[i][col]);
            }
            col--; //move to prev col //shrinking the matrix

            if( r <=row ){
              for(int i=col;i>=c;i--){
                ans.push_back(matrix[row][i]);
              }
              row--; //move to prev row //shrinking the matrix
            }

            if( c <=col){
              for(int i=row;i>=r;i--){
                ans.push_back(matrix[i][c]);
              }
              c++; //move to next col //shrinking the matrix
            }
        }
        return ans;
    }
};