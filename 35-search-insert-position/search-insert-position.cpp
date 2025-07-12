class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n=nums.size();
        int start=0;
        int end=nums.size()-1;
        int mid=0;
        int ans=0;
        while(start<=end){
            mid=start+(end-start)/2;
            if(nums[mid]==target){
                return mid;
            } else if(nums[mid]>target){
                ans=-1;
                end=mid-1;
            } else {
                ans=1;
                start=mid+1;
            }
        }
        return start;
    }
};