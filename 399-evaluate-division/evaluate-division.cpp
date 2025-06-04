class Solution {
public:
    double dfs(int src, int dst, vector<vector<vector<double>>>&graph, vector<bool>&vis){
        vis[src]=true;
        if(vis[dst]){ return 1; }
        for(auto edge : graph[src]){
            int neigh=edge[0];
            if(vis[neigh]){ continue; }
            double wt=edge[1];
            double ans=dfs(neigh, dst, graph, vis);
            if(ans !=-1){
                return ans*wt;
            }
        }
        return -1;
    }
    vector<double> calcEquation(vector<vector<string>>& eq, vector<double>& val, vector<vector<string>>& que) {
        unordered_map<string,int>mp;
        int node=0;
        for(int i=0;i<eq.size();i++){
            if(mp.find(eq[i][0])==mp.end()){
                mp[eq[i][0]]=node;
                node++;
            }
            if(mp.find(eq[i][1])==mp.end()){
                mp[eq[i][1]]=node;
                node++;
            }
        }
        vector<vector<vector<double>>>graph(node);
        for(int i=0;i<val.size();i++){
            string u=eq[i][0];
            string v=eq[i][1];
            graph[mp[u]].push_back({ (double)mp[v], val[i]});
            graph[mp[v]].push_back({ (double)mp[u], 1/val[i]});
        }

        vector<double>ans;
        for(int i=0;i<que.size();i++){
            string u=que[i][0];
            string v=que[i][1];
            if(mp.find(u)==mp.end() || mp.find(v)==mp.end()){
                ans.push_back(-1);
            } else {
                vector<bool>vis(node,false);
                ans.push_back(dfs(mp[u],mp[v],graph,vis));
            }
        }
        return ans;
    }
};