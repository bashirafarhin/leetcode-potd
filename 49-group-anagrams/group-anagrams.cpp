class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
     unordered_map<string,vector<string>> map;
     for(auto it : strs){
         string x=it;
         sort(x.begin(),x.end());
         if(map.find(x)==map.end()){map[x]={};}
         map[x].push_back(it);
     }
     vector<vector<string>> ans;
     for(auto it : map){
      ans.push_back(it.second);
     }
     return ans;  
    }
};