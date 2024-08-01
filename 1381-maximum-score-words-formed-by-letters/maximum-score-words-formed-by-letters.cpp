class Solution {
public:
    int helper(int i, vector<vector<int>>& wordsFreqArr, vector<int>& freq,
               vector<int>& score) {
        if (i == wordsFreqArr.size()) {
            return 0;
        }

        int take = 0;
        bool canTakeWord = true;

        for (int j = 0; j < 26; j++) {
            if (freq[j] < wordsFreqArr[i][j]) {
                canTakeWord = false;
            }
            freq[j] -= wordsFreqArr[i][j];
            take += (score[j]*wordsFreqArr[i][j]);
        }

        if (canTakeWord) {
            take += helper(i + 1, wordsFreqArr, freq, score);
        } else {
            take=0;
        }

        // restore freq
        for (int j = 0; j<26 ; j++) {
            freq[j] += wordsFreqArr[i][j];
        }

        int nottake = helper(i + 1, wordsFreqArr, freq, score);
        return max(take, nottake);
    }

    int maxScoreWords(vector<string>& words, vector<char>& letters,
                      vector<int>& score) {
        vector<int> freq(26, 0);
        for (char c : letters) {
            freq[c - 'a']++;
        }
        int n = words.size();
        vector<vector<int>> wordsFreqArr(n, vector<int>(26, 0));

        for (int i = 0; i < n; i++) {
            for (char ch : words[i]) {
                wordsFreqArr[i][ch - 'a']++;
            }
        }

        return helper(0, wordsFreqArr, freq, score);
    }
};