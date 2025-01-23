class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        vector<int>row(r,0);
        vector<int>col(c,0);
        int total=0;
        int isolated=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(!grid[i][j]){ continue; }
                total+=1;
                row[i]+=1;
                col[j]+=1;
            }
        }
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                // if in that row & col only that is present
                if(grid[i][j] && row[i]==1 && col[j]==1){
                    isolated++;
                }
            }
        }
        return total-isolated;
    }
};