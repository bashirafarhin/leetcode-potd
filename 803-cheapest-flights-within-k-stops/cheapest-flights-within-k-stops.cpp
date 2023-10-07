class Solution {
     vector<vector<int>>* make_adj(int v,vector<vector<int>>& edges){
        vector<vector<int>>* adj=new vector<vector<int>>[v];
        for(auto it : edges){
         vector<int> vec={it[1],it[2]};
         adj[it[0]].push_back(vec);
        }
        return adj;}
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
      vector<vector<int>>* adj=make_adj(n,flights);
      vector<int> dist(n,1e9);
      dist[src]=0;
      queue<pair<int,pair<int,int>>> q;
      q.push({0,{src,0}});
      while(!q.empty()){
         int stops=q.front().first;
         int node=q.front().second.first;
         int distance=q.front().second.second;
         q.pop();
         if(stops>k){continue;}
            for(auto it :adj[node]){
                int neigh=it[0];
                int wt=it[1];
                if(dist[neigh]>distance+wt && stops<=k){
                    dist[neigh]=distance+wt;
                    q.push({stops+1,{neigh,dist[neigh]}});
                }
            }
         }
      delete[] adj;
      if(dist[dst]==1e9){return -1;}
      return dist[dst];  
    }
};