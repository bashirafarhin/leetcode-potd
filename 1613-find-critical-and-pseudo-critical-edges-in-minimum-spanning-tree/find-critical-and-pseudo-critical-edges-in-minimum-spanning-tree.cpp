class Solution {
public:
    int findParent(int node, vector<int>&parent){
        if(parent[node]==node){
            return node;
        }
        return parent[node]=findParent(parent[node],parent);
    }

    void Union(int p1, int p2, vector<int>&parent, vector<int>&rank){
        if(rank[p1]>rank[p2]){
            parent[p2]=p1;
        }
        else if(rank[p1]<rank[p2]){
            parent[p1]=p2;
        } else {
            parent[p1]=p2;
            rank[p2]++;
        }
    }
    
    int MST(int n, vector<vector<int>>& edges, int skipEdge, int addEdge){
        int m=edges.size();
        int edgesUsed=0;
        vector<int> parent(n);
        vector<int> rank(n, 0);
        for (int i = 0; i < n; i++){
            parent[i] = i;
        }
        vector<vector<int>>mst;
        int mstWt=0;
        
        if(addEdge !=-1){
            int parent1=findParent(edges[addEdge][0],parent);
            int parent2=findParent(edges[addEdge][1],parent);
            Union(parent1,parent2,parent,rank);
            mstWt+=edges[addEdge][2];
            edgesUsed++;
        }
        for(int i=0;i<m;i++){
            if(skipEdge==i){
                continue;
            }
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            int parent1=findParent(u,parent);
            int parent2=findParent(v,parent);
            if(parent1 !=parent2){
                edgesUsed++;
                mstWt+=wt;
                Union(parent1,parent2,parent,rank);
            }
        }
        return (edgesUsed==n-1) ? mstWt : INT_MAX;
    }
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        int m=edges.size();
        for(int i=0;i<m;i++){
            edges[i].push_back(i);
        }
        sort(edges.begin(), edges.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[2] < b[2];
        });
        int mstWt=MST(n,edges,-1,-1);
        vector<int>critical;
        vector<int>pseudoCritical;
        for(int i=0;i<m;i++){
            if(MST(n,edges,i,-1)>mstWt){
                critical.push_back(edges[i][3]);
            } else {
                //pseudo critical-include or not mstWt remains same
                if (MST(n,edges,-1,i) == mstWt) {
                    pseudoCritical.push_back(edges[i][3]);
                }
            }
        }
        return {critical,pseudoCritical};
    }
};