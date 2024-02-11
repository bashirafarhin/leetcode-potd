class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
      int n=matrix.size();
      int m=matrix[0].size();
     
        for(int c=0;c<m;c++){
            int maxi=-1;
            for(int r=0;r<n;r++){
                maxi=max(maxi,matrix[r][c]);
            }
            for(int r=0;r<n;r++){
                if(matrix[r][c]==-1)
                  { matrix[r][c]=maxi;}
            }
        }
        return matrix;
    }
};