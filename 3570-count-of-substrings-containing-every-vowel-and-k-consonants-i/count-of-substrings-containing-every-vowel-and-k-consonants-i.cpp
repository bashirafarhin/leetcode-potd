class Solution {
public:
    bool isVowel(char& ch) {
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') == true;
    }

    int helper(string& word, unordered_map<char, int> mp, int start, int cons, int k) {
        int result=0;
        while (cons == k && mp.size() == 5) {
            result++;
            char st = word[start];
            if (isVowel(st)) {
                mp[st]--;
                if (mp[st] == 0) {
                    mp.erase(st);
                }
            } else {
                cons--;
            }
            start++;
        }
        return result;
    }


    int countOfSubstrings(string word, int k) {
        int n = word.length();
        unordered_map<char, int> mp;
        int cons = 0;
        int start = 0;
        int ans = 0;

        for (int end = 0; end < n; end++) {
            char ch = word[end];
            if (isVowel(ch)) {
                mp[ch]++;
            } else {
                cons++;
            }

            while (cons > k) {
                char st = word[start];
                if (isVowel(st)) {
                    mp[st]--;
                    if (mp[st] == 0) {
                        mp.erase(st);
                    }
                } else {
                    cons--;
                }
                start++;
            }

            if (cons == k && mp.size() == 5) {
                ans+=helper(word, mp, start, cons, k);
            }
        }
        return ans;
    }
};