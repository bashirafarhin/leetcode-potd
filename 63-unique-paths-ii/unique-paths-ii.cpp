class Solution {
public:

    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int R=grid.size();
        int C=grid[0].size();
        vector<int>prev(C,0);
        vector<int>curr(C,0);

        for(int r=0;r<R;r++){
            for(int c=0;c<C;c++){
                if(grid[r][c]==1){ continue; }
                else if( r==0 && c==0 ){ curr[c]=1; }
                else{
                   if(r-1>=0){ curr[c]+=prev[c]; }
                   if(c-1>=0){ curr[c]+=curr[c-1]; }
                }
            }
            prev=curr;
            for(int i=0;i<C;i++){ curr[i]=0; }
        }
        return prev[C-1];
    }
};