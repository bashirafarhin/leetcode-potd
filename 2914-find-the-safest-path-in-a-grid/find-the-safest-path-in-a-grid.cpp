class Solution {
public:
    bool canFind(int sf,vector<vector<int>>& grid){
        if(grid[0][0]<sf){
            return false;
        }
        int r=grid.size();
        int c=grid[0].size();
        vector<vector<int>>dxy={{-1,0},{0,1},{1,0},{0,-1}};
        vector<vector<int>>vis(r,vector<int>(c,0));
        queue<pair<int,int>>q;
        q.push({0,0});
        vis[0][0]=1;
        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            if(x==r-1 && y==c-1){
                return true;
            }
            q.pop();
            for(int i=0;i<4;i++){
                int nx=dxy[i][0]+x;
                int ny=dxy[i][1]+y;
                if(nx>=0 && nx<r && ny>=0 && ny<c && !vis[nx][ny] && grid[nx][ny]>=sf){
                    vis[nx][ny]=1;
                    q.push({nx,ny});
                }
            }
        }
        return false;
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        vector<vector<int>>dxy={{-1,0},{0,1},{1,0},{0,-1}};

        //preComputing safeness factor of each cell
        vector<vector<int>>safenessFactor(r,vector<int>(c,1e9));
        queue<pair<int,int>>q;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==1){
                    safenessFactor[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nx=dxy[i][0]+x;
                int ny=dxy[i][1]+y;
                if(nx>=0 && nx<r && ny>=0 && ny<c && safenessFactor[nx][ny]==1e9){
                    safenessFactor[nx][ny]=safenessFactor[x][y]+1;
                    q.push({nx,ny});
                }
            }
        }

        //calculating ans
        int ans=0;
        int start=0;
        int end=400;
        while(start<=end){
            int mid=(start+end)/2;
            //check for safeness factor==mid
            if(canFind(mid,safenessFactor)){
                ans=mid;
                start=mid+1;
            } else {
                end=mid-1;
            }
        }
        return ans;
    }
};