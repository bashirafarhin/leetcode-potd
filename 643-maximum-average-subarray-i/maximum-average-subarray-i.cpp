class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
      double ans=INT_MIN;
      double sum=0;
      for(int i=0;i<k;i++){
        sum+=nums[i];
      }
      ans=sum/k;
      for(int i=k;i<nums.size();i++){
        sum-=nums[i-k];
        sum+=nums[i];
        ans=max(ans,sum/k);
      }
      return ans;
    }
};