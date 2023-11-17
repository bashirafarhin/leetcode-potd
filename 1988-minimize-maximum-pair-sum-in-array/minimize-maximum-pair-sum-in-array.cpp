class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int mx=0;
        int n=nums.size();
        for(int i=0;i<n/2;i++)
        {
            int sum=nums[i] + nums[n-i -1];
            mx=max(mx , sum);
        }
        return mx;
    }
};