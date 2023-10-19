class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string p = "", n = "";
        for (auto x : s) {
            if (x == '#') {
                if (p.size() > 0) p.pop_back();
            } else {
                p += x;
            }
        }
        for (auto x : t) {
            if (x == '#') {
                if (n.size() > 0) n.pop_back();
            } else {
                n += x;
            }
        }
        return p == n;
    }
};