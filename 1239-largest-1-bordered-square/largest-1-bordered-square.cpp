class Solution {
public:
    //how to find diagonal, this is my problem
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        vector<vector<int>>rowWise(r,vector<int>(c,0));
        vector<vector<int>>colWise(r,vector<int>(c,0));
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(!grid[i][j]){ continue; }
                rowWise[i][j]+= j>0 ? rowWise[i][j-1]+1 : 1 ;
                colWise[i][j]+= i>0 ? colWise[i-1][j]+1 : 1 ;
            }
        }

        int side=0;
        for(int i=r-1;i>=0;i--){
            for(int j=c-1;j>=0;j--){
                int minSide=min(rowWise[i][j],colWise[i][j]);
                while(minSide>side){
                    if(colWise[i][j-minSide+1]>=minSide && rowWise[i-minSide+1][j]>=minSide){
                        side=minSide;
                        break;
                    }
                    minSide--;
                }
            }
        }
        return side*side;
    }
};