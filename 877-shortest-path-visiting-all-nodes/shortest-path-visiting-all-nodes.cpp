class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int v=graph.size();
        int destination=(1<<v)-1;
        set<pair<int,int>>vis;
        int dist=0;

        queue<pair<int,int>>q;
        for(int i=0;i<v;i++){
            int path=1<<i;
            q.push({i,path});
            vis.insert({i,path});
        }

        while(!q.empty()){
            int size=q.size();
            dist++;
            while(size--){
                int node=q.front().first;
                int currPath=q.front().second;
                q.pop();
                for(int neigh : graph[node]){
                    int path= currPath | (1<<neigh);
                    if(path==destination){ return dist; }
                    if(vis.find({neigh,path})==vis.end()){
                        vis.insert({neigh,path});
                        q.push({neigh,path});
                    }
                }
            }
        }
        return 0;
    }
};