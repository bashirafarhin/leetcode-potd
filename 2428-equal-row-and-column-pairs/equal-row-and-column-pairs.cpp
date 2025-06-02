class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n=grid.size();
        int ans=0;
        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                int k=0;
                for(;k<n;k++){
                    if(grid[k][col] != grid[row][k]){ break; }
                }
                if(k==n){ ans++; }
            }
        }
        return ans;
    }
};