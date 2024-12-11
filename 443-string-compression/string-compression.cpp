class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int i = 0;
        for (int j = 0; j < n;) {
            char curr = chars[j];
            int freq = 0;
            while (j < n && curr == chars[j]) {
                freq++;
                j++;
            }
            chars[i] = curr;
            i++;
            if (freq > 1) {
                string frequency=to_string(freq);
                int len=0;
                while (len<frequency.size()) {
                    chars[i] = frequency[len];
                    i++;
                    len++;
                }
            }
        }
        return i;
    }
};