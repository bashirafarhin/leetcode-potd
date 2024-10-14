class Solution {
public:
    static bool isVowel(char ch) {
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') ? true : false;
    }

    long long countOfSubstrings(string word, int k) {
        unordered_map<char, int> mp;
        int start = 0, end = 0, cons = 0, n = word.size();

        // precomputation
        vector<int> nextConsPos(n);
        int last = n;
        for (int i = n - 1; i >= 0; i--) {
            nextConsPos[i] = last;
            if (!isVowel(word[i])) {
                last = i;
            }
        }

        long long ans = 0;
        while (end < n) {
            isVowel(word[end]) ? mp[word[end]]++ : cons++;
            while (cons > k) {
                if (isVowel(word[start])) {
                    mp[word[start]]--;
                    if (!mp[word[start]]) { mp.erase(word[start]);  }
                } else {
                    cons--;
                }
                start++;
            }
            while (start < end && mp.size() == 5 && cons == k) {
                ans += abs(nextConsPos[end] - end);
                if (isVowel(word[start])) {
                    mp[word[start]]--;
                    if (!mp[word[start]]) { mp.erase(word[start]); }
                } else {
                    cons--;
                }
                start++;
            }
            end++;
        }
        return ans;
    }
};