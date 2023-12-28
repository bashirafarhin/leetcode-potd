class Solution {
    // bool func(int i,int j,string p,string s,vector<vector<int>>&dp){
    //     // if(i==p.length() && j==s.length()){return true;}
        // if(j==s.length()){
        //     for(int x=i;x<p.length();x++){
        //         if(p[x] !='*'){return false;}
        //     }
        //     return true;
        // }
        // if(i==p.length() || j==s.length()){return false;}
        // if(dp[i][j] !=-1){return dp[i][j];}
    //     if( (p[i]==s[j]) || (p[i]=='?') ){
    //         return dp[i][j]=func(i+1,j+1,p,s,dp);
    //     }
    //     if(p[i]=='*'){
    //     for(int k=j;k<=s.length();k++){
    //         if(func(i+1,k,p,s,dp)){return dp[i][j]=true;}
    //     }}
    //     return dp[i][j]=false;
    // }
public:
    bool isMatch(string s, string p) {

        int ls=s.length();
        int lp=p.length();
        vector<vector<bool>> dp(lp+1,vector<bool>(ls+1,false));


        for(int i=lp;i>=0;i--){
            for(int j=ls;j>=0;j--){

             if(i==lp && j==ls){
                 dp[i][j]=true;}
             
             else if(j==ls){
               int x=i;
               for( x=i;x<lp;x++){
                 if(p[x] !='*'){
                  break;}
                  }
               if(x==lp) {dp[i][j]=true;}}

             else if( (p[i]==s[j]) || (p[i]=='?') ){
               dp[i][j]=dp[i+1][j+1];}

             else if(p[i]=='*'){
               for(int k=j;k<=s.length();k++){
                if(dp[i+1][k]){
                    dp[i][j]=true;
                    break;}}
               }
            }
        }



        return dp[0][0];
    }
};