class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int R=heights.size();
        int C=heights[0].size();
        vector<vector<int>>dist(R,vector<int>(C,1e9));
        dist[0][0]=0;
        int dx[]={-1,0,1,0};
        int dy[]={0,1,0,-1};
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({0,{0,0}});
        while(!pq.empty()){
            int effort=pq.top().first;
            int r=pq.top().second.first;
            int c=pq.top().second.second;
            pq.pop();
            for(int i=0;i<4;i++){
                int newR=r+dx[i];
                int newC=c+dy[i];
                if(newR>=0 && newR<R && newC>=0 && newC<C){
                    int newEffort=max(effort,abs(heights[newR][newC]-heights[r][c]));
                    if(newEffort<dist[newR][newC]){
                        dist[newR][newC]=newEffort;
                        pq.push({newEffort,{newR,newC}});
                    }
                }
            }
        }
        return dist[R-1][C-1];
        }
};