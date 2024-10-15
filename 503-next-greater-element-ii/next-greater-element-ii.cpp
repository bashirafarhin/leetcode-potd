class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> st;
        vector<int> ans;
        for (int i = 2 * n - 1; i >= 0; i--) {
            while (!st.empty() && st.back() <= nums[i % n]) {
                st.pop_back();
            }
            if (i < n) {
                int num = st.empty() ? -1 : st.back();
                ans.push_back(num);
            }
            st.push_back(nums[i % n]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};