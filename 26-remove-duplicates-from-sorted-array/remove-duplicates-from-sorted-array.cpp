class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int place=0;
        int move=1;
        int n=nums.size();
        while(move<n){
            if(nums[move]>nums[place]){
                place++;
                swap(nums[move],nums[place]);
                move++;
            } else {
                move++;
            }
        }
        return place+1;
    }
};