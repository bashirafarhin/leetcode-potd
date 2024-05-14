class Solution {
public:
    string customSortString(string order, string s) {
        int freq[26]={0};
        for(char c : s){ freq[c-'a']++; }

        int i=0;
        for(char c : order){
            while(freq[c-'a']){
                s[i]=c;
                freq[c-'a']--;
                i++;
            }
        }

        for(int j=0;j<26;j++){
            while(freq[j]){
                s[i]=char('a'+j);
                freq[j]--;
                i++;
            }
        }
        return s;
    }
};