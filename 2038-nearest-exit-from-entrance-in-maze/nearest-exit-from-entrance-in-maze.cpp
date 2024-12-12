class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int r = maze.size();
        int c = maze[0].size();
        int steps = 0;
        vector<vector<int>> dxy = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        queue<pair<int, int>> q;
        q.push({entrance[0], entrance[1]});
        maze[entrance[0]][entrance[1]] = 'V';
        while (!q.empty()) {
            int size = q.size();
            steps++;
            while (size--) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for (auto dir : dxy) {
                    int newR = x + dir[0];
                    int newC = y + dir[1];
                    if (newR >= 0 && newR < r && newC >= 0 && newC < c && maze[newR][newC] == '.') {
                        if (newR == 0 || newR == r - 1 || newC == 0 || newC == c - 1) {
                            return steps;
                        }
                        q.push({newR, newC});
                        maze[newR][newC] = 'V';
                    }
                }
            }
        }
        return -1;
    }
};