class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int r=isWater.size();
        int c=isWater[0].size();
        vector<vector<int>>vis(r,vector<int>(c,0));
        vector<vector<int>>dxy={{-1,0},{0,1},{1,0},{0,-1}};
        queue<pair<int,int>>q;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(isWater[i][j]){
                    vis[i][j]=1;
                    q.push({i,j});
                }
            }
        }
        int level=0;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                int row=q.front().first;
                int col=q.front().second;
                isWater[row][col]=level;
                q.pop();
                for(int d=0;d<4;d++){
                    int x=row+dxy[d][0];
                    int y=col+dxy[d][1];
                    if(x>=0 && x<r && y>=0 && y<c && !vis[x][y]){
                        vis[x][y]=1;
                        q.push({x,y});
                    }
                }
            }
            level++;
        }
        return isWater;
    }
};