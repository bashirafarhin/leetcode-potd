class Solution {
     double solve(int r,int c,int steps,int N,vector<vector<vector<double>>>& dp){
     if(steps==0){return 1.0;}
     if(dp[r][c][steps] !=-1.0){return dp[r][c][steps];}
     int dx[]={1,1,-1,-1,2,2,-2,-2};
	 int dy[]={2,-2,2,-2,1,-1,1,-1};
	 double ans=0.0;
	 for(int i=0;i<8;i++){
	     int new_row=r+dx[i];
	     int new_col=c+dy[i];
	     if(new_row>=0 && new_row<N && new_col>=0 && new_col<N){
	         ans+= solve(new_row,new_col,steps-1,N,dp)/8;
	     }
	 }
	dp[r][c][steps]=ans;
    return ans;
        
    }
public:
    double knightProbability(int n, int k, int row, int column) {
     vector<vector<vector<double>>> dp(n,vector<vector<double>>(n,vector<double>(k+1,-1.0)));
	 return solve(row,column,k,n,dp);
   
    }
};