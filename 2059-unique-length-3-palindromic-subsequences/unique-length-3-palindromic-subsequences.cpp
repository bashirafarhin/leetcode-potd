class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.length();
        vector<int> arr(26, 0);
        int ans=0;
        for (int i = 0; i < n; i++) {
            if (arr[s[i] - 'a']) { continue; }
            arr[s[i]-'a']=1;
            for (int j = n - 1; j > i; j--) {
                if (s[j] == s[i]) {
                    unordered_set<char> st;
                    for (int k = i + 1; k < j; k++) {
                        st.insert(s[k]);
                    }
                    ans+=st.size();
                    break;
                }
            }
        }
        return ans;
    }
};