class Solution {
    /*store path is path is visited don`t go over there*/
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n=graph.size();
        if(n<=1){return 0;}
        set<pair<int,int>> vis;
        queue<pair<int,int>> q;
        int allVis=0;
        /*starting bfs from every node as it is mentioned we can start from any node*/
        /*pushing starting node and its path*/
        for(int i=0;i<n;i++){
         int path=1<<i;
         allVis=allVis | path;
         q.push({i,path});
         vis.insert({i,path});
        }

        int minPath=0;
        while(!q .empty()){
          int size=q.size();
          minPath++;
          while(size--){
              int node=q.front().first;
              int path=q.front().second;
              q.pop();
              for(auto neigh : graph[node]){
                  int nextpath=path | (1<<neigh);
                  if(nextpath==allVis){
                      return minPath;}
                  if(vis.find({neigh, nextpath})==vis.end()){
                      vis.insert({neigh, nextpath});
                      q.push({neigh, nextpath});}
              }
          }
        }
        return -1;
    }
};