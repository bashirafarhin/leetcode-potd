class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        int squares=0;
        int connectedSides=0;

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==1){
                    squares++;
                    if(j+1<c && grid[i][j+1]){ connectedSides++; }
                    if(i+1<r && grid[i+1][j]){ connectedSides++; }
                    
                }
            }
        }
        return 4*squares-2*connectedSides;
    }
};