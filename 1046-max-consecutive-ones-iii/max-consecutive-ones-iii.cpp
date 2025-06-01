class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int start = 0;
        int ans = 0;
        int flip = k;
        for (int end = 0; end < n; end++) {
            if (nums[end] == 0) {
                if (flip > 0) {
                    flip--;
                } else {
                    while (nums[start]) {
                        start++;
                    }
                    if (flip < k) {
                        flip++;
                        end--;
                    }
                    start++;
                }
            }
            ans = max(ans, end - start + 1);
        }
        return ans;
    }
};