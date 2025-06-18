class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int dst=n-1;
        for(int i=n-2;i>=0;i--){
            if(nums[i] !=0 && i+nums[i]>=dst){
                dst=i;
            }
        }
        return dst==0;
    }
};