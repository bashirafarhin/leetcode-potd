class Solution {

public:
    vector<vector<int>> shortest_distance(vector<vector<int>>&graph){
	 int n=graph.size();
	  for(int src=0;src<n;src++){
	    for(int row=0;row<n;row++){
	        for(int col=0;col<n;col++){
	            if(row !=col && row !=src && col !=src){
	                if(graph[row][col]>graph[row][src]+graph[src][col]){
	                    graph[row][col]=graph[row][src]+graph[src][col];
	                }
	            }
	        }
	    }
	  }
      return graph;
	 }
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        //make directed graph
        vector<vector<int>> graph(26,vector<int>(26,1e8));
        int len=original.size();
        for(int i=0;i<len;i++){
            if(graph[original[i]-'a'][changed[i]-'a']==1e8)
              {graph[original[i]-'a'][changed[i]-'a']=cost[i];}
            else{
            graph[original[i]-'a'][changed[i]-'a']=min(cost[i],graph[original[i]-'a'][changed[i]-'a'] );}
        }
        
        //shortest distance
        graph=shortest_distance(graph);
        //find answer
        long long ans=0;
        int n=source.size();
        for(int i=0;i<n;i++){
            if(source[i] !=target[i]){
             if(graph[source[i]-'a'][target[i]-'a'] ==1e8){return -1;}
             ans+=graph[source[i]-'a'][target[i]-'a'];
            }
        }
        return ans;
        
    }
};