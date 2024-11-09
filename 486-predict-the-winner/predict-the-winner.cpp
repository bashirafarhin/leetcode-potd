class Solution {
public:
    int helper(int start, int end, vector<int>& nums) {
        if (start > end) {
            return 0;
        }
        if (start == end) {
            return nums[start];
        }
        int pickStart=nums[start]-helper(start+1,end,nums);
        int pickEnd=nums[end]-helper(start,end-1,nums);
        return max(pickStart,pickEnd);
    }
    int predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        return helper(0,n-1,nums)>=0;
    }
};