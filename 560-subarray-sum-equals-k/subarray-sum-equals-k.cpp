class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int t = 0;
        int currS=0;
        unordered_map<int,int>mp;
        mp[0]=1;
        for (int i = 0; i < n; i++) {
            currS+=nums[i];
            if (mp.find(currS - k) != mp.end()) {
                t+=mp[currS-k];
            }
            mp[currS]+=1;
        }
        return t;
    }
};