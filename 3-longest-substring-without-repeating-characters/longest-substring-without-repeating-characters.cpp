class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        unordered_map<char, int> store;
        int start = 0;
        int curr = 0;
        for (int end = 0; end < s.length(); end++) {
            while (start<end && store.find(s[end]) != store.end()) {
                store.erase(s[start]);
                start++;
            }
            store[s[end]] = end;
            ans = max(ans, end - start + 1);
        }
        return ans;
    }
};