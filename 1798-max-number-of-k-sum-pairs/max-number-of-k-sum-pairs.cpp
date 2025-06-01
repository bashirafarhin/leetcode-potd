class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int ans=0;
        int start=0;
        int end=n-1;
        while(start<end){
            int sum=nums[start]+nums[end];
            if(sum<k){ start++; }
            else if(sum>k){ end--; }
            else {
                ans++;
                start++;
                end--;
            }
        }
        return ans;
    }
};