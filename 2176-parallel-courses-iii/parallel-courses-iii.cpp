class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        map<int, vector<int>> graph;
        vector<int> indegree(n, 0);
        vector<int> maxTime(n, 0);
        for(vector<int> &edge : relations) {
            int x = edge[0] - 1;
            int y = edge[1] - 1;
            graph[x].push_back(y);
            indegree[y]++;
        }
        queue<int> Q;
        for(int i = 0; i < n; i++) {
            if(indegree[i] == 0) {
                Q.push(i);
                maxTime[i] = time[i];
            }
        }
        while(!Q.empty()) {
            int node = Q.front();
            Q.pop();
            for(int child : graph[node]) {
                indegree[child]--;
                maxTime[child] = max(maxTime[child], maxTime[node] + time[child]);
                if(indegree[child] == 0) {
                    Q.push(child);
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++) {
            ans = max(ans, maxTime[i]);
        }
        return ans; 
    }
};