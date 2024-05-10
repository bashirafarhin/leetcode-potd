class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int start=0;
        int end=nums.size()-1;
        sort(nums.begin(),nums.end());
        while(start<end){
            if(nums[end]==-1*nums[start]){ return nums[end]; }
            else if(nums[end]<-1*nums[start]){ start++; }
            else { end--; }
        }
        return -1;
    }
};