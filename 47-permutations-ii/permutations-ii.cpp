class Solution {
public:
    //your previous solutions are not working because when swapping you are changing the order
    //and you can't sort the original array at every level as when you are going back you need the array in which you were iterating
    void helper(int ind, vector<int>& nums, vector<vector<int>>& ans) {
        if (ind == nums.size()) {
            ans.push_back(nums);
            return;
        }
        vector<int>arr=nums;
        sort(arr.begin()+ind, arr.end());
        for (int j = ind; j < arr.size(); j++) {
            if (j !=ind && arr[j-1]==arr[j]) {
                continue;
            }
            swap(arr[ind], arr[j]);
            helper(ind + 1, arr, ans);
            swap(arr[ind], arr[j]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        helper(0, nums, ans);
        return ans;
    }
};