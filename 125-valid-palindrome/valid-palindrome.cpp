class Solution {
public:
    bool isChar(char& ch) {
        return ('a' <= ch && ch <= 'z') || ('A' <= ch && ch <= 'Z') || ('0' <= ch && ch <= '9');;
    }

    bool isPalindrome(string s) {
        int i = 0;
        int j = s.size() - 1;
        while (i <= j) {
            int d = s[i] - s[j];
            if (!isChar(s[i])) {
                i++;
            } else if (!isChar(s[j])) {
                j--;
            } else if (toupper(s[i]) == toupper(s[j])) {
                i++;
                j--;
            } else {
                return false;
            }
        }
        return true;
    }
};