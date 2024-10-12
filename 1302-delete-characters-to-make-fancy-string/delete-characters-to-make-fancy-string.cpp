class Solution {
public:
    string makeFancyString(string s) {
        int n = s.length();
        stack<char> st;
        string ans = "";
        int i = 0;
        while (i < n) {
            int j = i;
            while (ans.size() != 0 && ans.back() == s[i] && i + 1 < n &&
                   s[i] == s[i + 1]) {
                i++;
            }
            if (j == i) {
                ans += s[i];
                i++;
            }
        }
        return ans;
    }
};