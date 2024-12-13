class Solution {
public:
    double dfs(int src, int dst, vector<vector<double>>&graph, vector<int>&vis){
        if(src==dst){
            return 1;
        }
        vis[src]=1;
        for(int neigh=0; neigh<graph.size(); neigh++){
            if(!vis[neigh] && graph[src][neigh]){
                double subAns=dfs(neigh,dst,graph,vis);
                if(subAns !=-1){
                    return (double)graph[src][neigh]*subAns;
                }
            }
        }
        vis[src]=0;
        return -1;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        //assign nodes
        unordered_map<string,int>mp;
        int n=0;
        for(int i=0;i<equations.size();i++){
            if(mp.find(equations[i][0])==mp.end()){
                mp[equations[i][0]]=n;
                n++;
            }
            if(mp.find(equations[i][1])==mp.end()){
                mp[equations[i][1]]=n;
                n++;
            }
        }
        //make graph
        vector<vector<double>>graph(n,vector<double>(n,0));
        for(int i=0;i<equations.size();i++){
            int u=mp[equations[i][0]];
            int v=mp[equations[i][1]];
            graph[u][v]=values[i];
            graph[v][u]=(double)1/values[i];
        }
        vector<double>ans;
        for(int i=0;i<queries.size();i++){
            if(mp.find(queries[i][0])==mp.end() || mp.find(queries[i][1])==mp.end()){
                ans.push_back(-1);
            } else {
                if(i==0){cout<<"hii";}
                int u=mp[queries[i][0]];
                int v=mp[queries[i][1]];
                vector<int>vis(n,0);
                ans.push_back(dfs(u,v,graph,vis));
            }
        }
        return ans;

    }
};