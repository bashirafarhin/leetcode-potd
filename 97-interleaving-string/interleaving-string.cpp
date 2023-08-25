class Solution {
public:
    int solve(string A,string B,string C,int a,int b,vector<vector<int>> &dp){
    
    if(a==A.length()){
     while(b<B.length()){
      if(C[a+b] !=B[b]){return 0;}
      b++;}
     return 1;}
    if(b==B.length()){
     while(a<A.length()){
      if(C[a+b] !=A[a]){return 0;}
      a++;}
     return 1;}
    
    int x=0,y=0;
    if(dp[a][b]==-1){
    if(C[a+b]==A[a]){
        x=solve(A,B,C,a+1,b,dp);}
    if(C[a+b]==B[b]){
        y=solve(A,B,C,a,b+1,dp);}
    dp[a][b]=x || y;}
    return dp[a][b];
    }
    
    bool isInterleave(string s1, string s2, string s3) {
     int a=s1.length();
     int b=s2.length();
     if(a + b !=s3.length()){return false;}
     vector<vector<int>> dp(a,vector<int>(b,-1));
     return solve(s1,s2,s3,0,0,dp);  
    }
};