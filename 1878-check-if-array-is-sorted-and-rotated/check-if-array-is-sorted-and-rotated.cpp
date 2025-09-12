class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size();
        int startingOfArray=0;
        for(int i=1;i<n;i++){
            if(nums[i-1]>nums[i]){
                startingOfArray=i;
                break;
            }
        }

        int min=0;
        for(int i=startingOfArray;i<n;i++){
            if(min<=nums[i]){
                min=nums[i];
            } else {
                return false;
            }
        }

        for(int i=0;i<startingOfArray;i++){
            if(min<=nums[i]){
                min=nums[i];
            } else {
                return false;
            }
        }
        return true;
    }
};