class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        for(int i=0;i<r;i++){
            if(grid[i][0]==0){
                //changed whole row
                for(int j=0;j<c;j++){
                    grid[i][j]^=1;
                }
            }
        }

        for(int i=0;i<c;i++){
            int cnt=0; //count 1s
            for(int j=0;j<r;j++){
              cnt+= grid[j][i]==1 ? 1 : 0 ;
            }
            if(cnt<r-cnt){
            for(int j=0;j<r;j++){
              grid[j][i]^=1;}
            }
        }

        int ans=0;
        for(int i=0;i<r;i++){
            int pow=1;
            for(int j=c-1;j>=0;j--){
               ans+=(pow)*grid[i][j];
               pow*=2;
            }
        }
        return ans;
        
    }
};