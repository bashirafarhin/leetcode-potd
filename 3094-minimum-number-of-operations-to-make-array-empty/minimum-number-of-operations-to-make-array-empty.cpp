class Solution {
    int solve(vector<int>& freqarr,int i,vector<int> &dp){
        if(i==freqarr.size()){
            return 0;}
        if(freqarr[i]==1){
            return 1e9;}
        if(dp[i] !=-1){return dp[i];}
        if(freqarr[i]==0){
         return solve(freqarr,i+1,dp);
        }
        if( !(freqarr[i]%3) ){
         return dp[i]=freqarr[i]/3 + solve(freqarr,i+1,dp);
        }

        int a=1e9;
        int b=1e9;
        if(freqarr[i]>=3){
          freqarr[i]-=3;
          a=1+solve(freqarr,i,dp);
          freqarr[i]+=3;
          }
        if(freqarr[i]>=2){
          freqarr[i]-=2;
          b=1+solve(freqarr,i,dp);
          freqarr[i]+=2;
          }
        return dp[i]=min(a, b);
    }
public:
    int minOperations(vector<int>& nums) {
     unordered_map<int,int> mp;
     for(int num : nums){
         mp[num]++;
     }
     vector<int> freqarr;
     for(auto it : mp){
         freqarr.push_back(it.second);
     }

     vector<int> dp(nums.size(),-1);
     int ans=solve(freqarr,0,dp);
     return ans>=1e9? -1 : ans;
    }
};