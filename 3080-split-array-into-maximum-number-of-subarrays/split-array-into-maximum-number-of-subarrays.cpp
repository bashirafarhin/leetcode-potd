class Solution {
public:
    int maxSubarrays(vector<int>& nums) {
        // for sum of score to be minimum , each subarray should have min
        // possible score what is the minimum possible score of subarray? answer
        // is---> total AND value of arr or less than that

        // observtion
        // if total AND value of array is non-zero then we cannot split the
        // array if total AND value of array is  then we can split the array
        int split = 0;
        int val = nums[0];

        for (int n : nums) {
            val &= n;
        }

        if (val) {
            return 1;
        }

        val = (1 << 20) - 1;
        for (int i = 0; i < nums.size(); i++) {
            val &= nums[i];
            if (val == 0) {
                split++;
                val = (1 << 20) - 1;
            }
        }
        if (val) {
            return split;
        }

        return split + 1;
    }
};