class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ans = -9223372036854775808;
        unordered_map<int, int> mp;
        int n = nums.size();
        vector<long long> prefix(n, 0);
        prefix[0] = nums[0];
        mp[nums[0]] = 0;
        bool flag=false;

        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + (long long)nums[i];

            if (mp.find(nums[i] - k) != mp.end()) {
                flag=true;
                int ind = mp[nums[i] - k];
                long long val = (ind >= 1) ? prefix[ind - 1] : 0;
                ans = max(ans, prefix[i] - val);
            }
            if (mp.find(nums[i] + k) != mp.end()) {
                flag=true;
                int ind = mp[nums[i] + k];
                long long val = (ind >= 1) ? prefix[ind - 1] : 0;
                ans = max(ans, prefix[i] - val);
            }
            if (mp.find(nums[i]) == mp.end() ||
                (prefix[mp[nums[i]]] > prefix[i])) {
                mp[nums[i]] = i;
            }
        }
        return flag==true? ans : 0;
    }
};