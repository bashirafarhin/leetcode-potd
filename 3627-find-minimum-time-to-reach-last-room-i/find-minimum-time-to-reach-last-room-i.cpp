class Solution {
public:
    int minTimeToReach(vector<vector<int>>& grid) {
        int R=grid.size();
        int C=grid[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        vector<vector<int>>minTime(R,vector<int>(C,INT_MAX));
        vector<vector<int>>dxy={{-1,0},{0,1},{1,0},{0,-1}};
        minTime[0][0]=0;
        pq.push({0,{0,0}});
        while(!pq.empty()){
            int t=pq.top().first;
            int r=pq.top().second.first;
            int c=pq.top().second.second;
            pq.pop();
            if(r==R-1 && c==C-1){ return t; }
            for(auto it : dxy){
                int nr=r+it[0];
                int nc=c+it[1];
                if(nr>=0 && nc>=0 && nr<R && nc<C){
                    int newTime=max(t+1,grid[nr][nc]+1);
                    if(minTime[nr][nc]>newTime){
                     minTime[nr][nc]=newTime;
                     pq.push({newTime,{nr,nc}});
                    }
                }
            }
        }
        return -1;
    }
};