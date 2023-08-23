class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    int r=mat.size();
	  int c=mat[0].size();
	  queue<pair<pair<int,int>,int>> q; //row,col,step
	  vector<vector<int>> vis(r,vector<int>(c,0));
	  vector<vector<int>> dist(r,vector<int>(c,0));
	  
	  for(int i=0;i<r;i++){
	      for(int j=0;j<c;j++){
	        if(mat[i][j]==0){
	            q.push({{i,j},0});
	            vis[i][j]=1;
	        }}}
	  int dx[]={-1,0,1,0};
	  int dy[]={0,1,0,-1};
	  while(!q.empty()){
	    auto i=q.front();
	    q.pop();
	    int row=i.first.first;
	    int col=i.first.second;
	    int steps=i.second;
	    dist[row][col]=steps;
	    for(int i=0;i<4;i++){
	        int new_r=row+dx[i];
	        int new_c=col+dy[i];
	        if(new_r>=0 && new_r<r && new_c>=0 && new_c<c && vis[new_r][new_c]==0){
	         vis[new_r][new_c]=1;
	         q.push({{new_r,new_c},steps+1});
	        }
	    }
	  }
	  return dist;
    }
};