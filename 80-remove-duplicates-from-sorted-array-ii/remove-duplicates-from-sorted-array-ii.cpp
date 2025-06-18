class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int freq = 0;
        int ele = nums[0];
        int i = 0;
        int j = 0;
        int n = nums.size();
        while (j < n) {
            if (ele == nums[j]) {
                freq++;
            } else {
                ele=nums[j];
                freq=1;
            }
            if(freq<=2){
                swap(nums[i], nums[j]);
                i++;
                j++;
            } else {
                j++;
            }
        }
        return i;
    }
};