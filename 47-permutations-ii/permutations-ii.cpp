class Solution {
public:
    void helper(int ind, vector<int>&nums, vector<vector<int>>&ans){
        if(ind==nums.size()){
            ans.push_back(nums);
            return;
        }
        unordered_set<int>st;
        for(int j=ind;j<nums.size();j++){
            if(st.find(nums[j])==st.end()){
                st.insert(nums[j]);
                swap(nums[ind],nums[j]);
                helper(ind+1, nums, ans);
                swap(nums[ind], nums[j]);
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        helper(0, nums, ans);
        return ans;
    }
};