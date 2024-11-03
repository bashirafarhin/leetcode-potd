using DataType = pair<pair<int,int>,pair<int,int>>;
class Solution {
public:
    int minTimeToReach(vector<vector<int>>& grid) {
        int R=grid.size();
        int C=grid[0].size();
        priority_queue<DataType,vector<DataType>,greater<DataType>>pq;
        vector<vector<int>>minTime(R,vector<int>(C,INT_MAX));
        vector<vector<int>>dxy={{-1,0},{0,1},{1,0},{0,-1}};
        minTime[0][0]=0;
        pq.push({{0,0},{0,0}});
        int move=0;
        while(!pq.empty()){
            int t=pq.top().first.first;
            int move=pq.top().first.second;
            int r=pq.top().second.first;
            int c=pq.top().second.second;
            pq.pop();
            if(r==R-1 && c==C-1){ return t; }
            move++;
            if(move==3){ move=1; }
            for(auto it : dxy){
                int nr=r+it[0];
                int nc=c+it[1];
                if(nr>=0 && nc>=0 && nr<R && nc<C){
                    int newTime=max(t+move,grid[nr][nc]+move);
                    if(minTime[nr][nc]>newTime){
                     minTime[nr][nc]=newTime;
                     pq.push({{newTime,move},{nr,nc}});
                    }
                }
            }
        }
        return -1;
    }
};