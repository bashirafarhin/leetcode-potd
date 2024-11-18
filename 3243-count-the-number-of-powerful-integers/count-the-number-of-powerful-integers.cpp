class Solution {
public:
    long long helper(int ind, int tight, string& num, int limit, string& s, long long dp[16][2]) {
        if (ind == num.size()) {
            return 1;
        }
        if(dp[ind][tight] !=-1){ return dp[ind][tight]; }
        int n = num.size() - ind;
        if (n <= s.size()) {
            if (tight) {
                if (num[ind] < s[s.size() - n]) {
                    return 0;
                }
                if (num[ind] == s[s.size() - n]) {
                    return helper(ind + 1, tight, num, limit, s, dp);
                }
                return 1;
            } else {
                return 1;
            }
        }
        int end = tight ? num[ind] - '0' : 9;
        long long ans = 0;
        for (int digit = 0; digit <= min(limit,end); digit++) {
            ans += helper(ind + 1, tight && (digit == end), num, limit, s, dp);
        }
        return dp[ind][tight]=ans;
    }
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        start--;
        string low = to_string(start);
        string high = to_string(finish);
        if (s.size() > high.size() || ((s.size() == high.size()) && s > high)) {
            return 0;
        }
        long long dp[16][2];
        memset(dp,-1,sizeof(dp));
        long long h=helper(0, 1, high, limit, s, dp);
        if(s.size() > low.size()){
            return h;            
        }
        memset(dp,-1,sizeof(dp));
        long long l= helper(0, 1, low, limit, s, dp);
        return h -l;
    }
};