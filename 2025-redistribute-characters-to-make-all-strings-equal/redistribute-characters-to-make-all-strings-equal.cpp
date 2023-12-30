class Solution {
public:
    bool makeEqual(vector<string>& words) {
        // freq% n==0 all charc
        unordered_map<char,int> mp;
        int n=words.size();
        for(int i=0;i<n;i++){
            int l=words[i].length();
            for(int j=0;j<l;j++){
                mp[words[i][j]]++;
            }
        }

        for(auto it : mp){
            if((it.second % n) !=0){
                return false;
            }
        }
        return true;
    }
};