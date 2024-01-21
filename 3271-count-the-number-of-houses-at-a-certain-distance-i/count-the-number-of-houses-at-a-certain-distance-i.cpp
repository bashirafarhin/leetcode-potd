class Solution {
    int finddis(vector<vector<int>>&adj,vector<int>&vis,int src,int dest){
        if(src==dest){return 0;}
        vis[src]=1;
        int d=1e9;
        for(auto neigh : adj[src]){
            if(vis[neigh]==0){
                d=min(d,1+finddis(adj,vis,neigh,dest));
            }
        }
        vis[src]=0;
        return d;
    }
public:
    vector<int> countOfPairs(int n, int x, int y) {
        vector<vector<int>> adj(n+1);

        bool flag=true;
        for(int i=1;i<n;i++){
            adj[i].push_back(i+1);
            adj[i+1].push_back(i);
        }
        adj[x].push_back(y);
        adj[y].push_back(x);

       vector<int> ans(n,0); 

        for(int i=1;i<=n;i++){
           for(int j=i+1;j<=n;j++){
            vector<int> vis(n+1,0);
            int d=finddis(adj,vis,i,j);
            if(1<=d<=n){ans[d-1]+=2;}
                
          }
        }
       
       


        return ans;
        
    }
};