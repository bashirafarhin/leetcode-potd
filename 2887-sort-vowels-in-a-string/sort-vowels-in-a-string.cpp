class Solution {
private:
    bool isVowel(char c) {
        return (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' ||
                c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }
public:
    string sortVowels(string s) {
        map<char, int> count; // in ASCII order 'A','E','I','O','U','a','e','i','o','u'
        for (char c : s) count[c] += isVowel(c);
        for (char& c : s) {
            if (isVowel(c)) {
                for (auto& it : count) {
                    if (it.second) {
                        c = it.first;
                        it.second--;
                        break;
                    }
                }
            }
        }
        return s;
    }
};