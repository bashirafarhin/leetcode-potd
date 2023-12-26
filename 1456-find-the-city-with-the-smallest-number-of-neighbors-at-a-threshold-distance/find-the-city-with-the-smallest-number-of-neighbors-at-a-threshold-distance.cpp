class Solution {
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
      return  matrix;
	 }

public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
    vector<vector<int>> matrix(n,vector<int>(n,-1));
    for(auto edge : edges){
        if(edge[0]==edge[1]){matrix[edge[0]][edge[0]]=0;}
        else{
        matrix[edge[0]][edge[1]]=edge[2];
        matrix[edge[1]][edge[0]]=edge[2];}}
    
    matrix=shortest_distance(matrix);
    int ans=0;
    int minCities=1e9;
    for(int i=0;i<n;i++){
        int numCities=0;
        for(int j=0;j<n;j++){
            if(matrix[i][j]<=distanceThreshold){numCities++;}
        }

        if(minCities>=numCities){
            ans=i;
            minCities=numCities;
        }
    }
     return ans;
    }
};