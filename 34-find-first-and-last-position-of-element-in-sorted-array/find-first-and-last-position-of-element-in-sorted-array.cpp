class Solution {
public:
    int binarySearch(vector<int>& nums, int target, bool include = true) {
        int n = nums.size();
        int start = 0;
        int end = n - 1;
        int ans = -1;
        bool ifInsideOfNextIf=false;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] == target) {
                ifInsideOfNextIf=include;
                ans = mid;
            }
            if (nums[mid] > target || (ifInsideOfNextIf)) {
                ifInsideOfNextIf=false;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int least = binarySearch(nums, target);
        if (least == -1) {
            return {-1, -1};
        }
        int max=binarySearch(nums, target, false);
        return {least, max};
    }
};