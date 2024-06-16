class Solution {
public:
    int solve(vector<int>& nums,int i,int sum, int target){
        if(i==nums.size()){
            return sum==target; }
        return solve(nums,i+1,sum-nums[i],target)+solve(nums,i+1,sum+nums[i],target);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
     return solve(nums,0,0,target);   
    }
};