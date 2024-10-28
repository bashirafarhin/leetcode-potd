class Solution {
public:
    int findSubstringInWraproundString(string s) {
        int n = s.length();
        vector<int> mp(26, 0);
        for (int ch = 0; ch < 26; ch++) {
            int i = 0;
            while (i < n) {
                if (s[i] == 'a' + ch) {
                    int j = i;
                    while (j + 1 < n && (s[j + 1] - s[j] == 1 || s[j + 1] - s[j] == -25)) {
                        j++;
                    }
                    mp[ch] = max(mp[ch], j - i + 1);
                    i=j;
                }
                i++;
            }
        }

        for(int n : mp){
            cout<<n<<" ";
        }
        return accumulate(mp.begin(), mp.end(), 0);
    }
};