class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
      int n=nums.size();
      if(n<3){return 0;}
      int ans=0;
      for(int i=0;i<(n-2);i++){
        for(int j=i;j<(n-2);j++){
          if(  (nums[j+1]-nums[j])==(nums[j+2]-nums[j+1]) ){ans++;}
          else {break;}
        }
      }
      
  

      
      return ans;
    }
};