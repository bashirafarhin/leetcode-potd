class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int ans=0;
        int l=0;
        int h=nums.size()-1;
        while(l<=h){
            int m=(l+h)/2;
            if(m==0 || nums[m-1]<nums[m]){
                ans=m;
                l=m+1;
            } else {
                h=m-1;
            }
        }
        return ans;
    }
};