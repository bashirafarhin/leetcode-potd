class Solution {
public:
    bool helper(int i, int j, string& s, string& p) {
        if (j == p.length()) {
            return i>=s.length();
        }
        bool firstMatch=false;
        if (i<s.length() && (s[i] == p[j] || p[j] == '.')) {
            firstMatch=true;
        }

        if (p[j+1] == '*') {
            bool notTake=helper(i,j+2,s,p);
            return notTake || (firstMatch && helper(i+1,j,s,p));
        }
        return firstMatch && helper(i+1,j+1,s,p);
    }
 bool isMatch(string s, string p) {
    return helper(0, 0, s, p);
}
};