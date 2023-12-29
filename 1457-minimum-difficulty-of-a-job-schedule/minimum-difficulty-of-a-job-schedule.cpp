class Solution {
    int solve(int i,vector<int>& jobDifficulty,int d,vector<vector<int>> &dp){
        if(d==0){
            if(i==jobDifficulty.size()){return 0;}
            return INT_MAX;
        }
        if(dp[i][d] !=-1){return dp[i][d];}
        int ans=INT_MAX;
        int maxDifficulty=0; //max jobDifficulty done on d day
        int n=jobDifficulty.size();
        for(int j=i;j<n;j++){
         maxDifficulty=max(maxDifficulty ,jobDifficulty[j]);
         int val=solve(j+1,jobDifficulty,d-1,dp);
         if(val !=INT_MAX){
             ans=min(val+maxDifficulty , ans);
         }
        }
        return dp[i][d]=ans;
    }
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
     int n=jobDifficulty.size();
     if(n<d){return -1;}
     vector<vector<int>> dp(n+1,vector<int>(d+1,-1));
     return solve(0,jobDifficulty,d,dp);
    }
};