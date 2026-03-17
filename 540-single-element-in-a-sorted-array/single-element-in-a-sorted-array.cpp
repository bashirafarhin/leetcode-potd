class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        int ans = nums[0];
        while (low <= high) {
            int mid = (high - low) / 2 + low;
            if (mid & 1) {
                mid--;
            }
            if (mid+1<n && nums[mid] == nums[mid + 1]) {
                low = mid + 2;
            } else {
                ans = nums[mid];
                high = mid - 1;
            }
        }
        return ans;
    }
};