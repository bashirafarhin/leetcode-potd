class Solution {
public:
    string invert(string s) {
        for (int i = 0; i < s.length(); i++) {
            s[i] = s[i] == '0' ? '1' : '0';
        }
        return s;
    }

    void buildString(string& s, int k) {
        if (s.length() < k) {
            string iandr = invert(s);
            reverse(iandr.begin(), iandr.end());
            s = s + "1" + iandr;
            buildString(s, k);
        }
    }

    char findKthBit(int n, int k) {
        if(n==1){ return '0'; }
        int finalLength = (1 << n) - 1;
        int mid = finalLength / 2 + 1;
        if (k == mid) {
            return '1';
        }
        int newK = k;
        bool invertFlag = false;
        if (k > mid) {
            newK = finalLength - k + 1;
            invertFlag = true;
        }
        string s = "0";
        buildString(s, newK);
        char ans = s[newK - 1];

        if (invertFlag)
            ans = (ans == '0') ? '1' : '0';

        return ans;
    }
};