class Solution {
public:
    int helper(int i, vector<pair<int,pair<int,int>>>&arr,vector<int>&dp){
        if(i==arr.size()){
            return 0;
        }
        if(dp[i] !=-1){
            return dp[i];
        }
        int take=0;
        int res=arr.size();
        int l=i+1;
        int h=arr.size()-1;
        int currEnd=arr[i].second.first;
        while(l<=h){
            int mid=(l+h)/2;
            if(arr[mid].first>=currEnd){
                res=mid;
                h=mid-1;
            } else {
                l=mid+1;
            }
        }
        
        take=arr[i].second.second + helper(res,arr,dp);
        int notTake=helper(i+1,arr,dp);
        return dp[i]=max(take,notTake);
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<pair<int,pair<int,int>>>arr;
        int n=endTime.size();
        for(int i=0;i<n;i++){
            arr.push_back({startTime[i],{endTime[i],profit[i]}});
        }
        sort(arr.begin(),arr.end());
        vector<int>dp(n,-1);
        return helper(0,arr,dp);
    }
};