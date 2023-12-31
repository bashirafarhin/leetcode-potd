class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        unordered_map<char,int> mp;
        int n=s.length();
        int ans=-1;
        for(int i=0;i<n;i++){
          if(mp.count(s[i]) !=0){
              ans=max(ans,i-mp[s[i]]-1);
          } else {
              mp[s[i]]=i;
          }
        }
        return ans;
    }
};