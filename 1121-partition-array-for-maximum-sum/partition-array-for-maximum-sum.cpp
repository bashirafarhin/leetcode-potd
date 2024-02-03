class Solution {
    int solve(vector<int>&arr,int i,int k,vector<int>&dp){
        if(i==arr.size()){return 0;}
        if(dp[i] !=-1){return dp[i];}
        int n=arr.size();
        int maxi=-1;
        int ans=0;
        for(int j=i;j<min(i+k,n);j++){
            maxi=max(maxi,arr[j]);
            ans= max( ans , maxi * (j-i+1) + solve(arr,j+1,k,dp));
        }
        return dp[i]=ans;
    }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int>dp(n+1,-1);
        return solve(arr,0,k,dp);
    }
};