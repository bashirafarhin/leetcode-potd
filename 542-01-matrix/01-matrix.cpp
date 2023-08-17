class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
      vector<vector<int>> dist(mat.size(), vector<int>(mat[0].size(), -1));
        queue<pair<int, int>> q;
        for(int i=0;i<mat.size();i++) {
            for(int j=0;j<mat[0].size();j++) {
                if(mat[i][j] == 0) {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        int d = 0;
        vector<vector<int>> dir({{-1,0}, {0, 1}, {1, 0}, {0, -1}});
        while(!q.empty()) {
            int n = q.size();
            while(n--) {
                auto &i = q.front();
                for(int j=0;j<4;j++) {
                    int x = i.first + dir[j][0];
                    int y = i.second + dir[j][1];

                    if(x >= 0 && y >= 0 && x < mat.size() && y < mat[0].size() && dist[x][y] == -1) {
                        dist[x][y] = d+1;
                        q.push({x, y});
                    }
                }
                q.pop();
            }
            d++;
        }

        return dist;   
    }
};