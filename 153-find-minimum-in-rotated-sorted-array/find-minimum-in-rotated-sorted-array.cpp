class Solution {
public:
    int findMin(vector<int>& nums) {
        int low=0;
        int high=nums.size()-1;
        int ans=1e9;
        while(low<=high){
            int mid = (high-low)/2 + low;
            if(nums[low]<=nums[mid]){
                ans=min(nums[low],ans);
                low=mid+1;
            } else {
                ans=min(nums[mid],ans);
                high=mid-1;
            }
        }
        return ans;
    }
};