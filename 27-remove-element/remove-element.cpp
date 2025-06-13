class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int start=0, end=nums.size()-1;
        while(start<=end){
            if(nums[start] !=val){ start++; }
            else if(nums[end]==val){ end--; }
            else{
                swap(nums[start],nums[end]);
                start++;
                end--;
            }
        }
        return end+1;
    }
};