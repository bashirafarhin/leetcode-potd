struct TrieNode {
    TrieNode* children[26];
    bool isEndOfWord;

    TrieNode() {
        isEndOfWord = false;
        for (int i = 0; i < 26; ++i) {
            children[i] = nullptr;
        }
    }
};

class Trie {
public:
    TrieNode* getNode() { return new TrieNode(); }

    void insert(TrieNode* root, const string& key) {
        TrieNode* curr = root;
        for (int i = 0; i < key.length(); i++) {
            int index = key[i] - 'a';
            if (curr->children[index] == nullptr) {
                curr->children[index] = getNode();
            }
            curr = curr->children[index];
        }
        curr->isEndOfWord = true;
    }
};

class Solution {
public:
    Trie trie;

    int helper(int i, const string& target, TrieNode* root, vector<int>& dp) {
        if (i == target.size()) {
            return 0;
        }
        if (dp[i] != -1) {
            return dp[i];
        }
        int ans = INT_MAX;
        TrieNode* curr = root;
        for (int j = i; j < target.size(); j++) {
            //in this we are not searching again n again the whole prefix
            int index = target[j] - 'a';
            if (curr->children[index] == nullptr) { break; }
            curr = curr->children[index];
            int res = helper(j + 1, target, root, dp);
            if (res != INT_MAX) {
                ans = min(ans, 1 + res);
            }
        }
        return dp[i] = ans;
    }

    int minValidStrings(vector<string>& words, const string& target) {
        TrieNode* root = trie.getNode();
        for (const string& word : words) {
            trie.insert(root, word);
        }
        int n = target.size();
        vector<int> dp(n, -1);
        int ans = helper(0, target, root, dp);
        return ans == INT_MAX ? -1 : ans;
    }
};
