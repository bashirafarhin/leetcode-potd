class Solution {
public:
    bool isVowel(char& ch){
        return ch=='a' || ch=='A' || ch=='e' || ch=='E' || ch=='i' || ch=='I'|| ch=='o' || ch=='O' || ch=='u' || ch=='U';
    }
    string reverseVowels(string s) {
        int start=0;
        int end=s.length()-1;
        while(start<end){
            if(!isVowel(s[start])){
                start++;
            }
            else if(!isVowel(s[end])){
                end--;
            } else {
                swap(s[start],s[end]);
                start++;
                end--;
            }
        }
        return s;
    }
};