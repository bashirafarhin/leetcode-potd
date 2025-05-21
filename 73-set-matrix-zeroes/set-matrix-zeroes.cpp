class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int R=matrix.size();
        int C=matrix[0].size();
        vector<int>rowArr(R,-1);
        vector<int>colArr(C,-1);
        for(int r=0;r<R;r++){
            for(int c=0;c<C;c++){
                if(matrix[r][c]==0){
                        rowArr[r]=1;
                        colArr[c]=1;
                    }
                }
            }

        for(int r=0;r<R;r++){
            if(rowArr[r]==1){
                for(int col=0;col<C;col++){
                    matrix[r][col]=0;
                }
            }
        }

        for(int c=0;c<C;c++){
            if(colArr[c]==1){
                for(int row=0;row<R;row++){
                    matrix[row][c]=0;
                }
            }
        }
    }
};