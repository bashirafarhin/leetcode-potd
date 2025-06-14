class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0;
        int majEle=-1;
        for(int i=0;i<nums.size();i++){
            if(count==0){
                count++;
                majEle=nums[i];
            }
            else if(majEle==nums[i]){
                count++;
            } else {
                count--;
            }
        }
        return majEle;
    }
};