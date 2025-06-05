class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int start = 0;
        int end = n - 1;
        int ans = 0;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if ((mid - 1 >= 0 && nums[mid - 1] < nums[mid]) || mid - 1 < 0) {
                ans = mid;
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return ans;
    }
};