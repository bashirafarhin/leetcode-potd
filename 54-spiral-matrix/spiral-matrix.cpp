class Solution {
public:
    void solve(vector<vector<int>>& mat,int i,int j,int r,int c,vector<int>&ans){
        if(i>r || j>c){ return ; }

        for(int k=j;k<=c;k++){
            ans.push_back(mat[i][k]);
        }
        for(int k=i+1;k<=(r-1);k++){
            ans.push_back(mat[k][c]);
        }

        if(i !=r){
           for(int k=c;k>=j;k--){
            ans.push_back(mat[r][k]);
           }
        }
        if(j !=c){
           for(int k=r-1;k>=(i+1);k--){
            ans.push_back(mat[k][j]);
           }
        }
        solve(mat,i+1,j+1,r-1,c-1,ans);
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
     int r=matrix.size();
     int c=matrix[0].size();
     vector<int>ans;
     solve(matrix,0,0,r-1,c-1,ans);
     return ans;

    }
};