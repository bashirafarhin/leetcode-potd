class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>mp;
        int ans=0;
        for (int i = 0; i < n; i++) {
            if(mp[nums[i]]){ continue; }
                int left=mp[nums[i] - 1];
                int right=mp[nums[i] + 1];
                int len = left+1+right;
                mp[nums[i]]=len;
                mp[nums[i]-left]=len;
                mp[nums[i]+right]=len;
                ans=max(ans,len);
        }
        return ans;
    }
};