class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        int ans=-1;
        while (low <= high) {
            int mid = (high - low) / 2 + low;
            if( (mid-1<0 || nums[mid-1]<nums[mid]) && (mid+1>=n || nums[mid]>nums[mid+1]) ){
                return mid;
            } else if(mid-1<0 || nums[mid-1]<nums[mid]){
                low=mid+1;
            } else {
                high=mid-1;
            }
        }
        return ans;
    }
};