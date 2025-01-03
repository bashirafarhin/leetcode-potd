class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n=nums.size();
        long long l=0;
        long long r=0;
        for(int n : nums){
            r+=n;
        }
        int ans=0;
        for(int i=0;i<n-1;i++){
            l+=nums[i];
            r-=nums[i];
            if(l>=r){ ans++; }
        }
        return ans;
    }
};