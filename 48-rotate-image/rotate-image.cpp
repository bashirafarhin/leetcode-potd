class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
      int n=matrix.size();
      int start=0;
      int end=n-1;
      while(start<end){
          for(int i=0;i<n;i++){
              swap(matrix[start][i],matrix[end][i]);
          }
          start++;
          end--;
      }
      start=0;
      end=n-1;
       while(start<end){
          for(int i=start;i<end;i++){
              swap(matrix[i][start],matrix[start][i]);
          }
          for(int i=start;i<=end;i++){
              swap(matrix[end][i],matrix[i][end]);
          }
          start++;
          end--;
        // return ;
      }
    }
};