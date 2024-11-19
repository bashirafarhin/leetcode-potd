class Solution {
public:
    int helper(int ind, int tight, int mask, string& nums, vector<vector<vector<int>>>&dp) {
        if (ind == nums.size()) {
            if(mask==1){ return 0; }
            return 1;
        }
        if(dp[ind][tight][mask] !=-1){
            return dp[ind][tight][mask];
        }
        int limit = tight ? nums[ind] - '0' : 9;
        int start=ind ? 0 : 1;
        int ans = 0;
        for (int digit = start; digit <= limit; digit++) {
            if(mask & (1<<digit)){ continue; }
            ans += helper(ind + 1, tight && digit == limit,mask | (1<<digit), nums, dp);
        }
        return dp[ind][tight][mask]=ans;
    }
    int countSpecialNumbers(int n) {
        string nums = to_string(n);
        int ans=0;
        int digits=9;
        int k=9;
        for(int size=1;size<nums.size();size++){
            ans+=k;
            if(size>1){
                digits--;
            }
            k=k*digits;
        }
        int mask=0;
        for(int i=0;i<10;i++){ mask|=(1<<i); }
        vector<vector<vector<int>>>dp(nums.size(),vector<vector<int>>(2,vector<int>(mask+1,-1)));
        return ans+helper(0, 1, 0, nums, dp);
    }
};