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
        //Dijikstra algo , just taking maximum edge prob instead minimum
        priority_queue<pair<double,int>>pq;
        vector<double> dist(n,0);
        pq.push({1,start_node});
        dist[start_node]=1;
        while(!pq.empty()){
            double curr_wt=pq.top().first;
            int node =pq.top().second;
            pq.pop();
            for(auto it : adj[node]){
                int neigh=it.first;
                double wt=it.second;
                if(dist[neigh]<dist[node]*wt)
                { dist[neigh]=dist[node]*wt;
                 pq.push({dist[node]*wt,neigh});}
            }
        }
        return dist[end_node];
    }
};