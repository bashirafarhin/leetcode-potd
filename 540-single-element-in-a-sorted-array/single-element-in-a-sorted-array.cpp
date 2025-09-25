class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int ans = -1;
        int l = 0;
        int h = n - 1;
        // if(n==1){ return nums[0]; }

        while (l <= h) {
            int m = (l + h) / 2;
            if (m & 1) {
                m--;
            }
            if (m==n-1 || nums[m] != nums[m+1]) {
                ans = nums[m];
                h = m-1;
            } else {
                l = m + 2;
            }
        }
        return ans;
    }
};