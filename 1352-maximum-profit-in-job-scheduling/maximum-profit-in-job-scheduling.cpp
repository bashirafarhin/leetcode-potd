class Solution {
    int solve(int i,vector<vector<int>>& jobs,vector<int>& startTime,vector<int> &dp){
        if(i==jobs.size()){return 0;}
        if(dp[i] !=-1){return dp[i];}
        int index=lower_bound(startTime.begin(),startTime.end(),jobs[i][1])-startTime.begin();
        int take=jobs[i][2]+solve(index,jobs,startTime,dp);
        
        int nottake=solve(i+1,jobs,startTime,dp);
        return dp[i]=max(take,nottake);

    }
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
     vector<vector<int>> jobs;
     int n=startTime.size();
     for(int i=0;i<n;i++){
         jobs.push_back({startTime[i],endTime[i],profit[i]});
     }
     sort(jobs.begin(),jobs.end());
     for(int i=0;i<n;i++){
      startTime[i]=jobs[i][0];
     }
     vector<int>dp(n,-1);
     return solve(0,jobs,startTime,dp);
    }
};