class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n=nums.size();
        double ans=INT_MIN;
        double sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(i==k-1){
                ans=max(ans,sum);
            } else if(i>=k) {
                sum-=nums[i-k];
                ans=max(ans,sum);
            }
        }
        return ans/k;
    }
};