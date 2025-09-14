class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int m=0;
        int l=0;
        int h=n-1;
        while(m<=h){
            if(nums[m]==2){
                swap(nums[m],nums[h]);
                h--;
            } else if(nums[m]==0){
                swap(nums[m],nums[l]);
                l++;
                m++;
            } else { m++; }
        }
    }
};