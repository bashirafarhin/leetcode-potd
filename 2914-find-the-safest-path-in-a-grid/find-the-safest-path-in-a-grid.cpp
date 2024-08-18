class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        vector<vector<int>>dxy={{-1,0},{0,1},{1,0},{0,-1}};

        //preComputing safeness factor of each cell
        vector<vector<int>>safenessFactor(r,vector<int>(c,1e9));
        queue<pair<int,int>>sq;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==1){
                    safenessFactor[i][j]=0;
                    sq.push({i,j});
                }
            }
        }
        while(!sq.empty()){
            int x=sq.front().first;
            int y=sq.front().second;
            sq.pop();
            for(int i=0;i<4;i++){
                int nx=dxy[i][0]+x;
                int ny=dxy[i][1]+y;
                if(nx>=0 && nx<r && ny>=0 && ny<c && safenessFactor[nx][ny]==1e9){
                    safenessFactor[nx][ny]=safenessFactor[x][y]+1;
                    sq.push({nx,ny});
                }
            }
        }

        //calculating ans
        priority_queue<pair<int,pair<int,int>>>pq;
        vector<vector<int>>vis(r,vector<int>(c,0));
        pq.push({safenessFactor[0][0],{0,0}});
        vis[0][0]=1;
        while(!pq.empty()){
            int x=pq.top().second.first;
            int y=pq.top().second.second;
            int sf=pq.top().first;
            pq.pop();
            if(x==r-1 && y==c-1){
                return sf;
            }
            for(int i=0;i<4;i++){
                int nx=dxy[i][0]+x;
                int ny=dxy[i][1]+y;
                if(nx>=0 && nx<r && ny>=0 && ny<c && !vis[nx][ny]){
                    vis[nx][ny]=1;
                    int nextSf=min(sf,safenessFactor[nx][ny]);
                    pq.push({nextSf,{nx,ny}});
                }
            }
        }
        return 0;
    }
};