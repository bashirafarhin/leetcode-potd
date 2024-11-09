class Solution {
public:
    int helper(int start, int end, vector<int>& nums) {
        if (start > end) {
            return 0;
        }
        if (start == end) {
            return nums[start];
        }
        int pickStart=nums[start]+min( helper(start+2,end,nums), helper(start+1,end-1,nums));
        int pickEnd=nums[end]+min( helper(start+1,end-1,nums), helper(start,end-2,nums));
        return max(pickStart,pickEnd);
    }
    int predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        int score1=helper(0, n - 1, nums);
        int score2=accumulate(nums.begin(),nums.end(),0)-score1;
        return score1>=score2;
    }
};