using DataType = pair<pair<int,int>,pair<int,int>>;class Solution {
public:
    int minTimeToReach(vector<vector<int>>& grid) {
        int R=grid.size();
        int C=grid[0].size();
        set<DataType>st;
        vector<vector<int>>minTime(R,vector<int>(C,INT_MAX));
        vector<vector<int>>dxy={{-1,0},{0,1},{1,0},{0,-1}};
        minTime[0][0]=0;
        st.insert({{0,0},{0,0}});
        while(!st.empty()){
            int t=st.begin()->first.first;
            int prevMove=st.begin()->first.second;
            int r=st.begin()->second.first;
            int c=st.begin()->second.second;
            int newMove=prevMove;
            newMove++;
            if(newMove==3){ newMove=1; }
            st.erase(st.begin());
            if(r==R-1 && c==C-1){ return t; }
            for(auto it : dxy){
                int nr=r+it[0];
                int nc=c+it[1];
                if(nr>=0 && nc>=0 && nr<R && nc<C){
                    int newTime=max(t+newMove,grid[nr][nc]+newMove);
                    if(minTime[nr][nc]>newTime){
                    if (st.find({{minTime[nr][nc],prevMove}, {nr, nc}}) != st.end()) {
                        st.erase({{minTime[nr][nc],prevMove}, {nr, nc}});
                    }
                     minTime[nr][nc]=newTime;
                     st.insert({{newTime,newMove},{nr,nc}});
                    }
                }
            }
        }
        return -1;
    }
};