class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<string> q;
        unordered_set<string> st(wordList.begin(), wordList.end());
        q.push(beginWord);
        int steps = 0;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                string word = q.front();
                if (word == endWord) {
                    return steps + 1;
                }
                q.pop();
                for (int i = 0; i < word.length(); i++) {
                    char og=word[i];
                    for (char ch = 'a'; ch <= 'z'; ch++) {
                        word[i] = ch;
                        if (st.find(word) !=st.end()) {
                            q.push(word);
                            st.erase(word);
                        }
                    }
                    word[i] = og;
                }
            }
            steps++;
        }
        return 0;
    }
};