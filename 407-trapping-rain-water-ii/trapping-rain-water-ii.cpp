class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int row=heightMap.size();
        int col=heightMap[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        vector<vector<bool>>vis(row,vector<bool>(col,false));
        // push left and right boundary
        for(int r=0;r<row;r++){
            pq.push({heightMap[r][0],{r,0}});
            pq.push({heightMap[r][col-1],{r,col-1}});
            vis[r][0]=true;
            vis[r][col-1]=true;
        }
        // push top and down boundary
        for(int c=0;c<col;c++){
            pq.push({heightMap[0][c],{0,c}});
            pq.push({heightMap[row-1][c],{row-1,c}});
            vis[0][c]=true;
            vis[row-1][c]=true;
        }
        // directions
        vector<vector<int>>dir={{-1,0},{0,1},{1,0},{0,-1}};
        int ans=0;
        while(!pq.empty()){
            int h=pq.top().first;
            int r=pq.top().second.first;
            int c=pq.top().second.second;
            pq.pop();
            for(int i=0;i<4;i++){
                int x = r+dir[i][0];
                int y = c+dir[i][1];
                if(x>=0 && x<row && y>=0 && y<col && !vis[x][y]){
                    ans+=max(h-heightMap[x][y],0);
                    vis[x][y]=true;
                    int maxH=max(h,heightMap[x][y]);
                    pq.push({maxH,{x,y}});
                }
            }
        }
        return ans;
    }
};