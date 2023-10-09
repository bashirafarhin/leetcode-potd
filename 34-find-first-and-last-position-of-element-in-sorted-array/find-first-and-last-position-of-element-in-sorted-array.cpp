class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
     int start=0;
     int end=nums.size()-1;
     int lb=-1;
     while(start<=end){
         int mid=(start+end)/2;
         if(nums[mid]==target){
            lb=mid;
            end=mid-1;}
         else if (nums[mid] >target){
             end=mid-1;}
         else{start=mid+1;}
     }
     
     if(lb==-1){return {-1,-1};}
     start=0;
     end=nums.size()-1;
     int ub=-1;
      while(start<=end){
         int mid=(start+end)/2;
         if(nums[mid]==target){
            ub=mid;
            start=mid+1;}
         else if (nums[mid] >target){
             end=mid-1;}
         else{start=mid+1;}
     }

     return {lb,ub};

    }
};