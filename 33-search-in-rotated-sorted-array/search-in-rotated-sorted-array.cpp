class Solution {
public:
    int search(vector<int>& nums, int target) {
        //identify which is the sorted half
        //perform a check to locate the target and on basis of that
        //eliminate the half array where you know your target can never lie there 
        int low = 0;
        int high = nums.size() - 1;
        while (low <= high) {
            int mid = ((high-low) / 2 ) + (low);
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[low] <= nums[mid]){
                if (nums[low] <= target && nums[mid] > target) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } else {
                if (nums[mid] < target && nums[high] >= target) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
};