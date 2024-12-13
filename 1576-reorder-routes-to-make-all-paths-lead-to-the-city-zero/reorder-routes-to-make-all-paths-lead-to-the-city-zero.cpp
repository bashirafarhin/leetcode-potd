class Solution {
public:
    int dfs(int src, vector<bool>& vis, vector<vector<pair<int, int>>>& g) {
        vis[src] = true;
        int ans = 0;
        for (auto [neigh, wt] : g[src]) {
            if (!vis[neigh]) {
                ans += (wt + dfs(neigh, vis, g));
            }
        }
        vis[src] = false;
        return ans;
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, int>>> graph(n);
        for (auto conn : connections) {
            graph[conn[0]].push_back({conn[1], 1});
            graph[conn[1]].push_back({conn[0], 0});
        }
        vector<bool> vis(n, false);
        return dfs(0, vis, graph);
    }
};