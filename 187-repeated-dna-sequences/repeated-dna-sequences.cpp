class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
     unordered_map<string,int> map;
     for(int i=0;i<s.length()-1;i++){
      map[s.substr(i,10)]++;
     }
     vector<string> ans;
     for(auto it : map){
         if(it.second>1){ans.push_back(it.first);}
     }
     return ans;
    }
};