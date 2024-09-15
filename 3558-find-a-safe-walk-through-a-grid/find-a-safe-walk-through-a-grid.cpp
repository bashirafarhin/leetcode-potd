class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int R = grid.size();
        int C = grid[0].size();
        vector<vector<int>> vis(R, vector<int>(C, 0));
        vector<vector<int>> dxy = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        priority_queue<pair<int, pair<int, int>>> pq;
        pq.push({health - grid[0][0], {0, 0}});
        vis[0][0] = 1;
        while (!pq.empty()) {
            int health = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();
            for (int i = 0; i < 4; i++) {
                int new_r = r + dxy[i][0];
                int new_c = c + dxy[i][1];
                if (0 <= new_r && new_r < R && 0 <= new_c && new_c < C &&
                    !vis[new_r][new_c] && (health - grid[new_r][new_c] > 0)) {
                    if (new_r == R - 1 && new_c == C - 1) {
                        return true;
                    }
                    vis[new_r][new_c]=1;
                    pq.push({health - grid[new_r][new_c], {new_r, new_c}});
                }
            }
        }
        return false;
    }
};