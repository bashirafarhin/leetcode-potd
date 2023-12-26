class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
         //create adj list
        vector<vector<pair<int, double>>> adj(n+1);
        for(int i=0;i<times.size();i++){
          int u=times[i][0];
          int v=times[i][1];
          int time=times[i][2];
          adj[u].push_back({v,time});
        }
        //Dijikstra algo
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int> dist(n+1,1e9);
        pq.push({0,k});
        dist[k]=0;
        while(!pq.empty()){
            int curr_time=pq.top().first;
            int node =pq.top().second;
            pq.pop();
            for(auto it : adj[node]){
                int neigh=it.first;
                int time=it.second;
                if(dist[neigh]>dist[node]+time)
                { dist[neigh]=dist[node]+time;
                 pq.push({dist[node]+time,neigh});}
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            if(dist[i]==1e9){return -1;}
            ans=max(ans,dist[i]);
        }
        return ans;
    }
};