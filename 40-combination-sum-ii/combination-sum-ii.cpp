class Solution {
public:
    void solve(vector<int>& nums,int i, int target,vector<int>&curr,vector<vector<int>>&ans){
        if(target==0){ 
            ans.push_back(curr);
            return; }
        
        for(int j=i;j<nums.size();j++){

         if(j>i && (nums[j-1]==nums[j])){ continue; }
         
         if(nums[j]<=target){
            curr.push_back(nums[j]);
            solve(nums,j+1,target-nums[j],curr,ans);
            curr.pop_back();
         } else {
            return;
         }
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>curr;
        sort(candidates.begin(),candidates.end());
        int n=candidates.size();
        solve(candidates,0,target,curr,ans);
        return ans;
    }
};