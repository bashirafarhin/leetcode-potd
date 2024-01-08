class Solution {
    bool solve(int i,int j,string s1, string s2, string s3,vector<vector<int>> &dp){
        
        if(i==0 && j==0){return true;}

        if(i==0){
            while(j >0){
             if (s2[j-1] !=s3[i+j-1]){return false;}
             j--;
            }
            return true;
        }

        if(j==0){
            
            while(i >0){
             if (s1[i-1] !=s3[i+j-1]){return false;}
             i--;
            }            
            return true;
        }
        
        if(dp[i][j] !=-1){return dp[i][j];}

        if( s1[i-1]==s3[i+j-1] && s2[j-1]==s3[i+j-1]){
            return   dp[i][j]=solve(i-1,j,s1,s2,s3,dp)|| solve(i,j-1,s1,s2,s3,dp) ;
        }

        if(s1[i-1]==s3[i+j-1]){
            return dp[i][j]=solve(i-1,j,s1,s2,s3,dp);
        }

        else if(s2[j-1]==s3[i+j-1]){
            return dp[i][j]=solve(i,j-1,s1,s2,s3,dp);
        }

        return dp[i][j]=false;

    }
public:
    bool isInterleave(string s1, string s2, string s3) {
     int l=s1.size();
     int m=s2.size();
     int n=s3.size();
     if(n != (l+m) ){return false;}
     vector<vector<int>>dp(l+1,vector<int>(m+1,-1));
     return solve(l,m,s1,s2,s3,dp);
    }
};