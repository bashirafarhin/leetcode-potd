class Solution {
public:
    void helper(int ind, vector<int> subSet, vector<int>&nums, vector<vector<int>>& ans) {
        if (ind == nums.size()) {
            ans.push_back(subSet);
            return;
        }
        subSet.push_back(nums[ind]);
        helper(ind + 1, subSet, nums, ans);
        subSet.pop_back();
        helper(ind + 1, subSet, nums, ans);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subSet;
        helper(0, subSet, nums, ans);
        return ans;
    }
};