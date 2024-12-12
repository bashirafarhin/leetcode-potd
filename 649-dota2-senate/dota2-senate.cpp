class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.size();
        for (int i = 0;; i++) {
            int ind = i % n;
            if (senate[ind] == 'K') { continue; }
            int next = ind + 1;
            while ( (next % n) != ind && (senate[next % n]=='K' || senate[next % n] == senate[ind])) { next++; }
            if (next % n== ind) {
                return senate[next % n] == 'R' ? "Radiant" : "Dire";
            } else {
                senate[next % n] = 'K';
            }
        }
        return "-1";
    }
};