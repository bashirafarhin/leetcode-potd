class Solution {
public:
    bool closeStrings(string word1, string word2) {
       int n=word1.size();
       int m=word2.size();
       if(n !=m){ return false; }
       unordered_map<char,int>freq1;
       for(char ch : word1){
        freq1[ch]++;
       }
       unordered_map<char,int>freq2;
       for(char ch : word2){
        freq2[ch]++;
       }
       //every character of word1 should be present in word2 and vice versa
       for(char ch : word1){
        if(freq2.find(ch)==freq2.end()){ return false; }
       }
       for(char ch : word2){
        if(freq1.find(ch)==freq1.end()){ return false; }
       }
       //frequency of words should match
       unordered_map<int,int>mp1;
       for(auto it : freq1){
        mp1[it.second]++;
       }
       unordered_map<int,int>mp2;
       for(auto it : freq2){
        mp2[it.second]++;
       }
       return mp1==mp2;
    }
};