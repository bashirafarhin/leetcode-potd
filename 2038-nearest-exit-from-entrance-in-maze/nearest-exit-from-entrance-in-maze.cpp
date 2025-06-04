class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int r = maze.size();
        int c = maze[0].size();
        vector<vector<bool>> vis(r, vector<bool>(c, false));
        vector<vector<int>> dxy = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        queue<pair<int, int>> q;
        q.push({entrance[0], entrance[1]});
        vis[entrance[0]][entrance[1]]=true;
        int d = 0;
        while (!q.empty()) {
            int size = q.size();
            d++;
            while (size--) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for (int i = 0; i < 4; i++) {
                    int nx = x + dxy[i][0];
                    int ny = y + dxy[i][1];
                    if (nx < 0 || nx == r || ny < 0 || ny == c ||
                        maze[nx][ny] == '+' || vis[nx][ny]) {
                        continue;
                    }
                    if (nx == 0 || nx == r - 1 || ny == 0 || ny == c - 1) {
                        return d;
                    }
                    q.push({nx, ny});
                    vis[nx][ny] = true;
                }
            }
        }
        return -1;
    }
};