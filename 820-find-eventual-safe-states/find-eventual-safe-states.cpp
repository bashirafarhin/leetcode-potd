class Solution {
    bool dfs(int sv,vector<vector<int>>& graph,vector<int> &visited,vector<int> &dp){
        if(dp[sv] !=-1){return dp[sv];} 
        visited[sv]=1;
        bool flag=true;
        for(auto neigh : graph[sv]){
            if(!visited[neigh]){
                if(!dfs(neigh,graph,visited,dp)){
                    flag=false;
                    break;}
            } else{
                flag=false;
                break;}
        }
        visited[sv]=0;
        dp[sv]=flag;
        return flag;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
     int V=graph.size();
     vector<int> visited(V,0);
     vector<int> dp(V,-1);
     vector<int> ans;
     for(int i=0;i<V;i++){
         if(dfs(i,graph,visited,dp)){ans.push_back(i);}
     }
     return ans;   
    }
};