class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.length();
        vector<int> arr(26, 0);
        unordered_set<string> st;
        for (int i = 0; i < n; i++) {
            if (arr[s[i] - 'a']) { continue; }
            arr[s[i] - 'a']=1;
            for (int j = n - 1; j > i; j--) {
                if (s[j] == s[i]) {
                    for (int k = i + 1; k < j; k++) {
                        string p = "";
                        p+=s[i];
                        p+=s[k];
                        p+=s[j];
                        st.insert(p);
                    }
                    break;
                }
            }
        }
        return st.size();
    }
};