class Solution {
public:
    void moveZeroes(vector<int>& nums) {
     int n=nums.size();
     int i=0;
	 int j=0;
	 while(i<n && j<n){
	     while(i<n && nums[i] !=0){i++;}
	     while(j<n && (nums[j] ==0 || j<i)){j++;}
	     if(i<n && j<n){swap(nums[i],nums[j]);}
	 }  
    }
};