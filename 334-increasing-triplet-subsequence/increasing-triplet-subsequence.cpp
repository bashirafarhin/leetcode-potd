class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        //longest increasing subsequence
        int n=nums.size();
        int first=INT_MAX;
        int second=INT_MAX;
        for(int i=0;i<n;i++){
            if(nums[i]>second){
                return true;
            } else if(first>nums[i]){
                first=nums[i];
            } else if(nums[i] !=first){
                second=nums[i];
            }
        }
        return false;
    }
};