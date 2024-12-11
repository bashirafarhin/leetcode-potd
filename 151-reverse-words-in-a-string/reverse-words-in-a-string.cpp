class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        string word = "";
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != ' ') {
                word += s[i];
            } else if (word.size() > 0) {
                ans = word + (ans.empty() ? "" : " ") + ans;
                word.clear();
            }
        }

        if(word.size()>0){
            ans = word + (ans.empty() ? "" : " ") + ans;
        }
        return ans;
    }
};