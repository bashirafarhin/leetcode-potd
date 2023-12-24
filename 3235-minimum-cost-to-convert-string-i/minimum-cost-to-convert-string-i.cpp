class Solution {

public:
    vector<vector<int>> shortest_distance(vector<vector<int>>&matrix){
	 int n=matrix.size();
	 vector<vector<int>> graph(n,vector<int>(n));
	 
	 for(int i=0;i<n;i++){
	     for(int j=0;j<n;j++){
	         if(matrix[i][j]==-1)
	          {graph[i][j]=1e9;}
	         else{
	             graph[i][j]=matrix[i][j];}}}
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
	  for(int i=0;i<n;i++){
	     for(int j=0;j<n;j++){
	         if(graph[i][j]==1e9)
	          {matrix[i][j]=-1;}
	         else{
	             matrix[i][j]=graph[i][j];}}
	  }
      return matrix;
	 }
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        //make directed graph
        vector<vector<int>> graph(26,vector<int>(26,-1));
        int len=original.size();
        for(int i=0;i<len;i++){
            if(graph[original[i]-'a'][changed[i]-'a']==-1)
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
             if(graph[source[i]-'a'][target[i]-'a'] ==-1){return -1;}
             ans+=graph[source[i]-'a'][target[i]-'a'];
            }
        }
        return ans;
        
    }
};