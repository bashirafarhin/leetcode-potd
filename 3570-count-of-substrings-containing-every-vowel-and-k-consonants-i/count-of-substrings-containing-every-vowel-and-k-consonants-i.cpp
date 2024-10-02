class Solution {
public:
    bool isVowel(char& ch) {
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' ||
                ch == 'u') == true;
    }

    int countOfSubstrings(string word, int k) {
        int n = word.length();
        unordered_map<char, int> mp;
        int cons = 0;
        int start = 0;
        int ans = 0;

        for(int end=0;end<n;end++){
            char ch=word[end];
            if(isVowel(ch)){
                mp[ch]++;
            } else {
                cons++;
            }

            while(cons>k){
                char st = word[start];
                if(isVowel(st)){
                    mp[st]--;
                    if(mp[st]==0){ mp.erase(st); }
                } else {
                    cons--;
                }
                start++;
            }

            if(cons==k && mp.size()==5){
                unordered_map<char,int>tempMap=mp;
                int tempStart=start;
                int tempCons=cons;
                while(tempCons==k && tempMap.size()==5){
                    ans++;
                    char tempSt=word[tempStart];
                    if(isVowel(tempSt)){
                        tempMap[tempSt]--;
                        if(tempMap[tempSt]==0){ tempMap.erase(tempSt); }
                    } else {
                        tempCons--;
                    }
                    tempStart++;
                }
            }
        }
        return ans;
    }
};