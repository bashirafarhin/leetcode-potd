class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ans = 0;
        int cnt = 0;
        int start = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                cnt++;
            } else if (k > 0) {
                k--;
                cnt++;
            } else {
                while (nums[start] != 0) {
                    start++;
                    cnt--;
                }
                start++;
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};