class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n, 0);
        vector<int> suffix(n, 0);
        prefix[0] = nums[0];
        suffix[n - 1] = nums[n - 1];
        vector<int> ans(n, 0);

        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] * nums[i];
        }
        for (int i = n - 2; i > 0; i--) {
            suffix[i] = suffix[i + 1] * nums[i];
        }

        for (int i = 0; i < n; i++) {
            int right = i + 1 < n ? suffix[i + 1] : 1;
            int left = i - 1 >= 0 ? prefix[i - 1] : 1;
            ans[i] = left * right;
        }
        return ans;
    }
};