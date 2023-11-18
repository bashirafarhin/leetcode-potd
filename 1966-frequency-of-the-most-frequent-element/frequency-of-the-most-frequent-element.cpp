class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int n = nums.size(), left = 0, ret = 0;
        long currSum = 0;
        
        for (int right = 0; right < n; right++) {
            currSum += (long) nums[right];

            while (left < right && ((long) nums[right] * (right - left + 1)) - currSum > k) {
                currSum -= nums[left++];
            }

            ret = max(ret, right - left + 1);
        }

        return ret;
    }
};