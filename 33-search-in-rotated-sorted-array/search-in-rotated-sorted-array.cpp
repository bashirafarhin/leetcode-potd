class Solution {
public:
    int search(vector<int>& nums, int t) {
        int n = 0;
        int l = 0;
        int h = nums.size() - 1;
        while (l <= h) {
            int m=(l+h)/2;
            if (nums[m] == t) {
                return m;
            }

            if (nums[m] < nums[h]) {
                if (nums[m]<=t && t<=nums[h]) {
                    l = m + 1;
                } else {
                    h = m - 1;
                }
            } else {
                if (nums[l]<=t && t<=nums[m]) {
                    h = m - 1;
                } else {
                    l = m + 1;
                }
            }
        }
        return -1;
    }
};