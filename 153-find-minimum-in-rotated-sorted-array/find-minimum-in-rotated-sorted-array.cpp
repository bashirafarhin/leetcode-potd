class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = 0;
        int l = 0;
        int h = nums.size() - 1;
        int ans=INT_MAX;
        while (l <= h) {
            int m=(l+h)/2;
            ans=min(ans,nums[m]);
            if (nums[m] < nums[h]) {
                h = m - 1;
            } else {
               l = m + 1;
            }
        }
        return ans;
    }
};