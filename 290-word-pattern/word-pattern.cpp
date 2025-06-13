class Solution {
public:
    bool wordPattern(string pattern, string s) {
        int n=s.size();
        unordered_map<string, char>wordToChar;
        unordered_map<char, string>charToWord;
        int j=0;
        for(int i=0;i<pattern.size();i++){
            string word="";
            while(j<n && s[j] !=' '){
                word+=s[j];
                j++;
            }
            j++;
            if((wordToChar.find(word) != wordToChar.end()) && wordToChar[word] !=pattern[i]){ return false; }
            if((charToWord.find(pattern[i]) != charToWord.end()) && charToWord[pattern[i]] !=word){ return false; }
            wordToChar[word]=pattern[i];
            charToWord[pattern[i]]=word;
        }
        return j==s.size()+1;
    }
};