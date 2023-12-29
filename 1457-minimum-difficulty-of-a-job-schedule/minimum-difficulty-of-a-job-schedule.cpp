class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
     int n=jobDifficulty.size();
     if(n<d){return -1;}
     vector<vector<int>> dp(n+1,vector<int>(d+1,INT_MAX));
     dp[n][0]=0;
     for(int i=n;i>=0;i--){
         for(int day=1;day<=d;day++){
             int ans=INT_MAX;
             int maxDifficulty=0; //max jobDifficulty done on d day
             for(int j=i;j<n;j++){
              maxDifficulty=max(maxDifficulty ,jobDifficulty[j]);
              if(dp[j+1][day-1] !=INT_MAX){
                ans=min(dp[j+1][day-1]+maxDifficulty , ans);}
             }
             dp[i][day]=ans;
           }
     }
     return dp[0][d];
    }
};