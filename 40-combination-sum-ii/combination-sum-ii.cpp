class Solution {
    void solve(int i,vector<int>& candidates,int target,vector<vector<int>>&ans,vector<int>&arr){
        if(target==0){
            ans.push_back(arr);
            return ; }
        int n=candidates.size();

        for(int j=i;j<n;j++){
         if(candidates[j]>target){return ;}
         if( j>i && (candidates[j] == candidates[j-1]) ){continue;}
            arr.push_back(candidates[j]);
            solve(j+1,candidates,target-candidates[j],ans,arr);
            arr.pop_back();}
        return ;        
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> arr;
        sort(candidates.begin(),candidates.end());
        solve(0,candidates,target,ans,arr);
        return ans;
    }
};