class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        //create adj list
        vector<vector<pair<int, double>>> adj(n);
        for(int i=0;i<edges.size();i++){
          int u=edges[i][0];
          int v=edges[i][1];
          double p=succProb[i];
          adj[u].push_back({v,p});
          adj[v].push_back({u,p});
        }
        //Dijikstra algo , just taking maximum edge prob insetaed minimum
        priority_queue<pair<double,int>>pq;
        // priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;
        pq.push({1,start_node});
        vector<int>vis(n,0);
        while(!pq.empty()){
            double curr_wt=pq.top().first;
            int node =pq.top().second;
            pq.pop();
            vis[node]=1;
            if(node==end_node){return curr_wt;}
            for(auto it : adj[node]){
                int neigh=it.first;
                double wt=it.second;
                if(!vis[neigh]){pq.push({curr_wt*wt,neigh});}
            }
        }
        return 0;
    }
};