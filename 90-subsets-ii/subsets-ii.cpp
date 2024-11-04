class Solution {
public:
    void helper(int ind, vector<int>& nums, vector<int>& subSet, vector<vector<int>>& ans) {
        if (ind == nums.size()) {
            ans.push_back(subSet);
            return;
        }
        subSet.push_back(nums[ind]);
        helper(ind + 1, nums, subSet, ans);
        subSet.pop_back();
        while(ind+1<nums.size() && nums[ind]==nums[ind+1]){ ind++; }
        helper(ind + 1, nums, subSet, ans);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> subSet;
        helper(0, nums, subSet, ans);
        return ans;
    }
};