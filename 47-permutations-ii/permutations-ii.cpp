class Solution {
public:
    //you can't use this condition to skip nums[j-1]==nums[j] as you're distorting the order, then don't the order
    void helper(vector<int>&curr, vector<int>& nums, vector<int>&used, vector<vector<int>>& ans) {
        if (curr.size() == nums.size()) {
            ans.push_back(curr);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if(used[i]){ continue; }
            if (i>0 && nums[i-1]==nums[i] && used[i-1]) {
                continue;
            }
            used[i]=1;
            curr.push_back(nums[i]);
            helper(curr, nums, used, ans);
            curr.pop_back();
            used[i]=0;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>used(nums.size(),0);
        vector<int>curr;
        vector<vector<int>> ans;
        helper(curr, nums, used, ans);
        return ans;
    }
};