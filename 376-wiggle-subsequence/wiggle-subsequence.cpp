class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n=nums.size();
        int inc=1; //we want maximum alternating sequence
        int dec=1;
        for(int i=0;i<n-1;i++){
            if(nums[i]>nums[i+1]){
                inc=dec+1;
            }
            else if(nums[i]<nums[i+1]){
                dec=inc+1;
            }
        }
        return max(inc,dec);
    }
};