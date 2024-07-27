class Solution {
public:
    int helper(int i,int d,vector<int>&arr,vector<vector<int>>&dp){
        if(d==1){
            if(i !=0){ i--; }
            return *max_element(arr.begin()+i,arr.end());
        }
        if(arr.size()-i<d){ return 1e9; }
        if(dp[i][d] !=-1){
            return dp[i][d];
        }
        int res=1e9;
        int n=arr.size();
        int currDiff=arr[i];
        for(int j=i;j<n;j++){
            currDiff=max(currDiff,arr[j]);
            res=min(res,currDiff+helper(j+1,d-1,arr,dp));
        }
        return dp[i][d]=res;
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
      int n=jobDifficulty.size();
      vector<vector<int>>dp(n,vector<int>(d+1,-1));
      int res=helper(0,d,jobDifficulty,dp);  
      return res>=1e9 ? -1 : res;
    }
};