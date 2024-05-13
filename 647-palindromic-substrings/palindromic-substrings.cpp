class Solution {
public:
    int count(string s, int start, int end) {
        int ans=0;
        while (start>=0 && end<s.size() && s[start] == s[end]) {
            ans++;
            start--;
            end++;
        }
        return ans;
    }

    int countSubstrings(string s) {
        int ans = 0;
        for (int i = 0; i < s.size() ; i++) {
            ans += count(s, i, i) + count(s, i, i + 1);
        }
        return ans;
    }
};