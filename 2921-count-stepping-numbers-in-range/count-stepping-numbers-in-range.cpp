class Solution {
public:
    int mod=1e9+7;
    string minusOne(string s) {
        int n = s.size();
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] > '0') {
                s[i]--;
                break;
            } else {
                s[i] = '9';
            }
        }
        //remove leading zeroes;
        if (s[0] == '0' && s.size() != 1) {
            s.erase(s.begin());
        }
        return s;
    }
    int helper(int ind, int tight, int last, int placed, string& num, int dp[101][2][10][2]) {
        if (ind == num.size()) {
            return placed? 1 : 0;
        }
        if (dp[ind][tight][last][placed] != -1) {
            return dp[ind][tight][last][placed];
        }
        int limit = tight ? num[ind] - '0' : 9;
        int ans = 0;
        if (placed) {
            if (last-1 >= 0 && last-1 <= limit) { ans=(ans%mod+helper(ind+1, tight && (last-1 == limit), last-1, placed, num, dp)%mod)%mod; }
            if (last+1 <= 9 && last+1 <= limit) { ans=(ans%mod+helper(ind+1, tight && (last+1 == limit), last+1, placed, num, dp)%mod)%mod; }
        } else {
            for (int digit = 0; digit <= limit; digit++) {
                ans=(ans%mod+helper(ind+1, tight && (digit == limit), digit, digit>0, num, dp)%mod)%mod;
            }
        }
        return dp[ind][tight][last][placed] = ans;
    }

    int countSteppingNumbers(string low, string high) {
        string Low = minusOne(low);
        int dp[101][2][10][2];
        memset(dp, -1, sizeof(dp));
        int h = helper(0, 1, 0, 0, high, dp);
        memset(dp, -1, sizeof(dp));
        int l = helper(0, 1, 0, 0, Low, dp);
        return max(0, (h - l+mod)%mod);
    }
};