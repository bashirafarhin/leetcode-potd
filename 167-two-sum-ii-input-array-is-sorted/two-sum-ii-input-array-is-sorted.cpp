class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int start=0;
        int end=nums.size()-1;
        vector<int>ans(2,0);
        while(start<end){
            int sum=nums[start]+nums[end];
            if(sum>target){
                end--;
            } else if(sum<target){
                start++;
            } else {
                ans[0]=start+1;
                ans[1]=end+1;
                break;
            }
        }
        return ans;
    }
};