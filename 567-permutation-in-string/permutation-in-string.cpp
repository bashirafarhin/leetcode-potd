class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length()>s2.length()){ return false; }
        vector<int>freq1(26,0);
        vector<int>freq2(26,0);
        for(char ch : s1){ freq1[ch-'a']++; }
        int len1=s1.length();
        int len2=s2.length();
        for(int i=0;i<len1;i++){
            freq2[s2[i]-'a']++;
        }
        if(freq1==freq2){ return true; }
        for(int i=len1;i<len2;i++){
            freq2[s2[i]-'a']++;
            freq2[s2[i-len1]-'a']--;
            if(freq1==freq2){ return true; }
        }
        return false;
    }
};