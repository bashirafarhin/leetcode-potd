class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ans = 0;
        int deleted = 0;
        int start = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i]==0 && deleted==0) {
                deleted=1;
            } else if(nums[i]==0){
                while (nums[start] != 0) {
                    start++;
                }
                start++;
            }
            ans = max(ans, i-start);
        }
        return ans;
    }
};