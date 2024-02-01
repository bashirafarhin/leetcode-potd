class Solution {
    bool solve(vector<int>&nums,int i,int k){
        if(i==nums.size()){ return true; }

        if( (nums[i+1]-nums[i])<=k && (nums[i+2]-nums[i+1])<=k && (nums[i+2]-nums[i])<=k ){
            return solve(nums,i+3,k); }

        return false;
    }
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
     int n=nums.size();
     vector<vector<int>> ans;
     if(n % 3){ return ans;}

     sort(nums.begin(),nums.end());

     if( solve(nums,0,k) ){
         for(int i=0;i<n;i+=3){
             ans.push_back({nums[i],nums[i+1],nums[i+2]});
         }
     }
     return ans;
    }
};