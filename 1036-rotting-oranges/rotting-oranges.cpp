class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        vector<vector<int>> dxy = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        queue<pair<int, int>> q;
        for(int x=0;x<r;x++){
            for(int y=0;y<c;y++){
                if(grid[x][y]==2){
                    q.push({x,y});
                }
            }
        }
        int time = 0;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for (int i = 0; i < 4; i++) {
                    int nx = x + dxy[i][0];
                    int ny = y + dxy[i][1];
                    if (nx>=0 && nx<r && ny>=0 && ny<c && grid[nx][ny]==1) {
                        grid[nx][ny]=2;
                        q.push({nx, ny});
                    }
                }
            }
            time++;
        }

        for(int x=0;x<r;x++){
            for(int y=0;y<c;y++){
                if(grid[x][y]==1){
                    return -1;
                }
            }
        }
        if(!time){
            return 0;
        }        
        return time-1;
    }
};