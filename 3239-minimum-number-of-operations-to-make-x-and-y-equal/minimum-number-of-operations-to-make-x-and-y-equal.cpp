class Solution {
public:
    int minimumOperationsToMakeEqual(int x, int y) {
        if (x < y) {
            return y - x;
        }
        queue<pair<int, int>> q;
        unordered_map<int, int> vis;
        q.push({x, 0});

        while (!q.empty()) {
            int size = q.size();
            while (size--) {

                int node = q.front().first;
                int dist = q.front().second;
                q.pop();
                if (node == y) {
                    return dist;
                }
                if (node % 11 == 0 && vis[node / 11] == false) {
                    vis[node / 11] = true;
                    q.push({node / 11, dist + 1});
                }
                if (node % 5 == 0 && vis[node / 5] == false) {
                    vis[node / 5] = true;
                    q.push({node / 5, dist + 1});
                }
                if (node - 1 >= 1 && vis[node - 1] == false) {
                    vis[node - 1] = true;
                    q.push({node - 1, dist + 1});
                }
                if (node + 1 <= x + 15 && vis[node + 1] == false) {
                    vis[node + 1] = true;
                    q.push({node + 1, dist + 1});
                }
            }
        }
        return -1;
    }
};