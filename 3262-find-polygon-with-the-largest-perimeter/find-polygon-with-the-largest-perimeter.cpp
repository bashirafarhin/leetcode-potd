class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0;
        for (int n : nums) {
            sum += (long long)n;
        }
        sort(nums.begin(),nums.end());
        
        for (int i = n - 1; i >= 2; i--) {
            sum -= nums[i];
            long long longestSide = nums[i];
            if (longestSide < sum) {
                return sum + longestSide;
            }
        }

        return -1;
    }
};