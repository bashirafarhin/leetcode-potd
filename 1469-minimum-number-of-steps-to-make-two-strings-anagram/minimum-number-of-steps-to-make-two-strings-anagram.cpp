class Solution {
public:
    int minSteps(string s, string t) {
     unordered_map<char,int> freq;
     for(int i=0;i<s.length();i++){
         freq[s[i]]++;
     }
     for(int i=0;i<t.length();i++){
         freq[t[i]]--;
     }     
     int ans=0;
     for(auto it : freq){
       if(it.second>0){
           ans+=it.second;
       }
     }
     return ans;
    }
};