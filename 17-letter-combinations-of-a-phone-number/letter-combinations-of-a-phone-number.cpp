class Solution {
public:
    vector<string> dfs(int i, string digits, vector<vector<string>>& dict) {
        if (i == digits.size()-1) {
            return dict[digits[i]-'0'];
        }
        vector<string>curr={};
        vector<string> subStrings = dfs(i + 1, digits, dict);
        for (string ch : dict[digits[i] - '0']) {
            for (string st : subStrings) {
                curr.push_back(ch + st);
            }
        }
        return curr;
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0){
            return {};
        }
        vector<vector<string>> dict = {{},
                               {},
                               {"a", "b", "c"},
                               {"d", "e", "f"},
                               {"g", "h", "i"},
                               {"j", "k", "l"},
                               {"m", "n", "o"},
                               {"p", "q", "r", "s"},
                               {"t", "u", "v"},
                               {"w", "x", "y", "z"}};
        return dfs(0, digits, dict);
    }
};