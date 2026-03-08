class Solution {
public:
    string makeAltString(int n, int startsWith) {
        string s = "";
        for (int i = 0; i < n; i++) {
            if (i & 1) {
                s += startsWith == 1 ? '0' : '1';
            } else {
                s += startsWith == 0 ? '0' : '1';
            }
        }
        return s;
    }

    int minFlips(string s) {
        int n = s.size();
        string ns = s + s;
        string oneAlt = makeAltString(2*n, 1);
        string zeroAlt = makeAltString(2*n, 0);
        int flipsIfstartsWithOne = 0;
        int flipsIfstartsWithZero = 0;

        for (int i = 0; i < n; i++) {
            flipsIfstartsWithOne += (ns[i] != oneAlt[i]);
            flipsIfstartsWithZero += (ns[i] != zeroAlt[i]);
        }
        int ans = min(flipsIfstartsWithOne, flipsIfstartsWithZero);
        for (int i = 1; i < n; i++) {
            int prev= i-1;
            int end = i + n - 1;

            flipsIfstartsWithOne -= (ns[prev] != oneAlt[prev]);
            flipsIfstartsWithZero -= (ns[prev] != zeroAlt[prev]);

            flipsIfstartsWithOne += (ns[end] != oneAlt[end]);
            flipsIfstartsWithZero += (ns[end] != zeroAlt[end]);
            
            int curr = min(flipsIfstartsWithOne, flipsIfstartsWithZero);
            ans = min( ans, curr);

        }
        return ans;
    }
};