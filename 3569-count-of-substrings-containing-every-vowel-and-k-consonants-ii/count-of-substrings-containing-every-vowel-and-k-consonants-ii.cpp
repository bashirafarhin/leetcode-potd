class Solution {
public:
    bool isVowel(char& ch) {
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') == true;
    }

    long long countOfSubstrings(string word, int k) {
        int n = word.length();
        unordered_map<char, int> mp;

        vector<int>nextCons(n);
        int lastCons=n;
        for(int i=n-1;i>=0;i--){
            nextCons[i]=lastCons;
            if(!isVowel(word[i])){
                lastCons=i;
            }
        }

        int cons = 0;
        int start = 0;
        long long ans = 0;
        for (int end = 0; end < n; end++) {
            char ch = word[end];
            if (isVowel(ch)) {
                mp[ch]++;
            } else {
                cons++;
            }

            while (start<=end && cons > k) {
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

            while (start<end && cons == k && mp.size() == 5) {
                ans += (nextCons[end] - end);
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
        }
        return ans;
    }
};