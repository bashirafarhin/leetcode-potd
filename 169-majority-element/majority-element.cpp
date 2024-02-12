class Solution {
public:
    int majorityElement(vector<int>& nums) {
       int count=0;
       int ele=-1;
       for(int i=0;i<nums.size();i++){
           if(count==0){
               count=1;
               ele=nums[i];
           }
           else if (ele==nums[i]){ count++; }
           else { count--; }
       }
       return ele;
    }
};