class Solution {
public:
    void boundary(vector<vector<int>>& matrix,int r,int c,int row,int col,vector<int>&ans){
        if( r>row || c>col){ return; }

        for(int i=c;i<=col;i++){
         ans.push_back(matrix[r][i]);
        }
        for(int i=r+1;i<=row;i++){
         ans.push_back(matrix[i][col]);
        }
        //if last row is also not the 1st row
        if( r != row ){
            for(int i=col-1;i>=c;i--){
              ans.push_back(matrix[row][i]);
            }
        }
        //if last col is also not the 1st col
        if( c != col ){
            for(int i=row-1;i>r;i--){
              ans.push_back(matrix[i][c]);
            }
        }

        boundary(matrix,r+1,c+1,row-1,col-1,ans); //shrinking the matrix
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>ans;
        int row=matrix.size();
        int col=matrix[0].size();
        boundary(matrix,0,0,row-1,col-1,ans);
        return ans;
    }
};