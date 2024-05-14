class Solution {
public:
    bool solve(vector<int>&nums,int i,int currSum,int target,int k,vector<int>&vis){
        
        if(k<0){
            return true;
        }
        if(currSum==0){
            return solve(nums,0,target,target,k-1,vis);
        }
        if(i==nums.size()){
            return false;
        }

        bool take=false;
        if( !(nums[i]>target || vis[i] || (i>0 && nums[i]==nums[i-1] && !vis[i-1]) ) ){
            vis[i]=1;
            take=solve(nums,i+1,currSum-nums[i],target,k,vis);
            vis[i]=0;
            if(take){ return true; }
        }

        return solve(nums,i+1,currSum,target,k,vis);

        
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
       int sum=accumulate(nums.begin(),nums.end(),0);
       if(sum%k !=0){ return false; }
       int target=sum/k;
       vector<int>vis(nums.size(),0);
       sort(nums.begin(),nums.end(),greater<int>());
       return solve(nums,0,0,target,k,vis);
    }
};