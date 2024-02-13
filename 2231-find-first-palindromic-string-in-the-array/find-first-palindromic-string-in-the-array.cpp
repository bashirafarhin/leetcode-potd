class Solution {
public:
    string firstPalindrome(vector<string>& words) {
     for(string word : words){
         int start=0;
         int end=word.length()-1;
         while(start<end && word[start]==word[end]){ start++; end--; }
         if(start>=end){ return word; }
     } 
     return "";
    }
};