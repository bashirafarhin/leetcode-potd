class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n=strs.size();
        map<vector<int>,vector<string>>mp;
        for(int i=0;i<n;i++){
            vector<int> freq(26,0);
            for(char c : strs[i]){ freq[c-'a']++;}
            mp[freq].push_back(strs[i]);
        }
        vector<vector<string>> ans;
        for(auto it : mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};