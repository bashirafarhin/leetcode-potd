class Solution {
public:
    string decodeString(string s) {
        int n = s.size();
        string ans = "";
        int i = 0;
        while (i < n) {
            if ('a' <= s[i] && s[i] <= 'z') {
                ans += s[i];
                i++;
            } else {
                string num = "";
                while ('0' <= s[i] && s[i] <= '9') {
                    num += s[i];
                    i++;
                }
                int freq = stoi(num);
                int open = 1;
                int closed = 0;
                int start = i + 1;
                i += 2;
                while (open != closed) {
                    if (s[i] == ']') {
                        closed++;
                    } else if (s[i] == '[') {
                        open++;
                    }
                    i++;
                }
                string substr = decodeString(s.substr(start, i - start - 1));
                for (int f = 0; f < freq; f++) {
                    ans += substr;
                }
            }
        }
        return ans;
    }
};