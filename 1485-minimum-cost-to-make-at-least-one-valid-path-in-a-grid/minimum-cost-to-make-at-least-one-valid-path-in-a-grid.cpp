class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int R=grid.size();
        int C=grid[0].size();
        vector<vector<int>>dir={{},{0,1},{0,-1},{1,0},{-1,0}};
        set<pair<int,pair<int,int>>>path;
        vector<vector<int>>cost(R,vector<int>(C,INT_MAX));
        cost[0][0]=0;
        path.insert({0,{0,0}});
        while(!path.empty()){
            auto cell=*path.begin();
            path.erase(path.begin());
            int c=cell.first;
            int row=cell.second.first;
            int col=cell.second.second;
            if(row==R-1 && col==C-1){ return c; }
            for(int i=1;i<=4;i++){
                int nr=row+dir[i][0];
                int nc=col+dir[i][1];
                if(nr<0 || nr>=R || nc<0 || nc>=C){ continue; }
                int currCost=c+(i==grid[row][col] ? 0 : 1);
                if(cost[nr][nc]>currCost){
                    if(path.find({cost[nr][nc],{nr,nc}}) !=path.end()){
                        path.erase(path.find({cost[nr][nc],{nr,nc}}));
                    }
                    cost[nr][nc]=currCost;
                    path.insert({currCost,{nr,nc}});
                }
            }
        }
        return -1;
    }
};