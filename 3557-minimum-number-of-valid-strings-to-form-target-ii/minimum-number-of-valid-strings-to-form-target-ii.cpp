class Solution {
public:
    vector<int> prefix(string s) {
    int n = s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

    int minValidStrings(vector<string>& words, string target) {
        vector<vector<int>> pi;
        for (auto word : words) {
            pi.push_back(prefix(word+'#'+target));
        }

        int res=0;
        int len=target.size();
        while(len>0){
            int match=0;
            for(int i=0;i<words.size();i++){
                match=max(match,pi[i][words[i].size()+len]);
            }
            if(match==0){
                return -1;
            }
            res++;
            len-=match;
        }
        return res;
    }
};