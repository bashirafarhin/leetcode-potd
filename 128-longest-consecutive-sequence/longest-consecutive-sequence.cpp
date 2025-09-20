class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> mp;
        int ans = 0;

        for (int x : nums) {
            if (mp.count(x)) continue; // avoid duplicates

            int left = mp.count(x - 1) ? mp[x - 1] : 0;
            int right = mp.count(x + 1) ? mp[x + 1] : 0;
            int length = left + right + 1;

            mp[x] = length;
            // update boundaries
            mp[x - left] = length;
            mp[x + right] = length;

            ans = max(ans, length);
        }

        return ans;
    }
};
