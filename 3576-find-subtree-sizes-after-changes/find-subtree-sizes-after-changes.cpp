class Solution {
public:
    int countSubtree(vector<vector<int>>& graph, int src, vector<int>& ans) {
        int n = graph.size();
        int count = 1;
        for (int neigh : graph[src]) {
            count += countSubtree(graph, neigh, ans);
        }
        ans[src] = count;
        return count;
    }
    void dfs(int node, int src, vector<int>& parent, string& s, vector<pair<int,int>>&changes) {
        if(s[node]==s[src]){
            changes.push_back({node, src});
            return ;
        }
        if(src==0){
            return ;
        }
        dfs(node,parent[src],parent,s,changes);
    }

    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        vector<pair<int,int>>changes;
        for(int i=1;i<n;i++){
            dfs(i,parent[i],parent,s,changes);
        }
        for(auto it : changes){
            parent[it.first]=it.second;
        }

        // count subtree from all nodes;
        vector<vector<int>> graph(n);
        for (int i = 1; i < n; i++) {
            graph[parent[i]].push_back(i);
        }
        vector<int> ans(n, 0);
        countSubtree(graph, 0, ans);
        return ans;
    }
};