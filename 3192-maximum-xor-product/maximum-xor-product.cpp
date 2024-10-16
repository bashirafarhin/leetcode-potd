class Solution {
public:
    int mod = 1e9 + 7;
    int maximumXorProduct(long long a, long long b, int n) {
        long long axorx = 0;
        long long bxorx = 0;
        for (long long i = 49; i >= 0; i--) {
            bool aBit = a & (1LL << i);
            bool bBit = b & (1LL << i);
            if (i >= n) {
                if (aBit) {
                    axorx = axorx | (1LL << i);
                }
                if (bBit) {
                    bxorx = bxorx | (1LL << i);
                }
            } else {
                if (aBit == bBit) {
                    axorx = axorx | (1LL << i);
                    bxorx = bxorx | (1LL << i);
                    continue;
                }
                if (axorx > bxorx) {
                    bxorx = bxorx | (1LL << i);
                } else {
                    axorx = axorx | (1LL << i);
                }
            }
        }
        axorx %= mod;
        bxorx %= mod;
        return (axorx * bxorx) % mod;
    }
};