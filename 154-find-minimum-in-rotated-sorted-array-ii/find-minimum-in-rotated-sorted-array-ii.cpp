class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0;
        int h=nums.size()-1;
        int ans=nums[l];
        while(l<=h){
            int m=l+(h-l)/2;
            ans=nums[m];
            if(nums[m]==nums[h]){
                h=h-1;
            } else if(nums[m]>nums[h]){
                l=m+1;
            } else {
                h=m;
            }
        }
        return ans;
    }
};