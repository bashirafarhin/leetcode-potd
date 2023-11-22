class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int m = nums.size();
        int n = 0;
        for(vector<int>& arr : nums) if(arr.size()>n) n = arr.size();
        vector<vector<int>> vec((m+n),vector<int>());
        for(int i = 0; i < m; i++){
            for(int j = 0; j < nums[i].size(); j++){
                vec[i+j].push_back(nums[i][j]);
            }
        }
        vector<int> ans;
        for(int i = 0; i < m+n; i++){
            int l = vec[i].size()-1;
            for(int j = l; j >= 0; j--) ans.push_back(vec[i][j]);
        }
        return ans;
    }
};