class Solution {
public:
    string makeFancyString(string s) {
        int n = s.length();
        stack<char> st;
        string ans = "";
        int i=0;
        while (i < n) {
            if (!st.empty() && st.top() == s[i]) {
                st.push(s[i]);
                ans+=s[i];
                while (i<n && st.top() == s[i]) {
                    i++;
                }
            } else {
                st.push(s[i]);
                ans+=s[i];
                i++;
            }
        }
        return ans;
    }
};