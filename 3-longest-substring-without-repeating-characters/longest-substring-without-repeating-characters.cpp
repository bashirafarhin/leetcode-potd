class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int>mp;
        int ans=0;
        int start=0;
        for(int end=0;end<s.size();end++){
            while(mp.find(s[end]) != mp.end()){
                mp[s[start]]--;
                if(mp[s[start]]==0){
                    mp.erase(s[start]);
                }
                start++;
            }
            mp[s[end]]=1;
            ans=max(ans, end-start+1);
        }
        return ans;
    }
};