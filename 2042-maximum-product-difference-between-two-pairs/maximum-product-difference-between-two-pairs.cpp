class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        // int n=nums.size();
        // return nums[n-2]*nums[n-1]-nums[0]*nums[1];
        int n=nums.size();
        int max1=-1e9,max2=-1e9;
        int min1=1e9,min2=1e9;
        for(int i=0;i<n;i++){
            if(nums[i]>max1){
                max2=max1;
                max1=nums[i];}
            else if(nums[i]>max2){
                max2=nums[i];}
            if(min1>nums[i]){
                min2=min1;
                min1=nums[i];}
            else if(min2>nums[i]){
                min2=nums[i];}
        }
        return max1*max2-min1*min2;
    }
};