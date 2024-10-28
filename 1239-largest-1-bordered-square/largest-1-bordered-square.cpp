class Solution {
public:
    int helper(int& sr, int& sc, vector<vector<int>>& grid){
        int r=grid.size();
        int c=grid[0].size();
        int len=0;
        int i=sr;
        int j=sc;
        while(i<r && j<c){
            bool flag=true;
            if(grid[sr][j] !=1 || grid[i][sc] !=1){
                return len*len;
            }
            for(int k=sr;k<=i;k++){
                if(grid[k][j]!=1){
                    flag=false;
                    break;
                }
            }
            for(int k=sc;k<=j;k++){
                if(grid[i][k]!=1){
                    flag=false;
                    break;
                }
            }
            i++;
            j++;
            if(flag){ len=max(len,i-sr); }
        }
        return len*len;
    }
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        int sq=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                sq=max(sq,helper(i,j,grid));
            }
        }
        return sq;
    }
};