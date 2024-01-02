class Solution {
public:
     vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        vector<vector<int>> arr;
        while(! mp.empty()){
         vector<int> row;
         auto it=mp.begin();
         while( it !=mp.end()){
             row.push_back(it->first);
             mp[it->first]--;
             if(mp[it->first]==0){it=mp.erase(it);}
             else{it++;}
         }
         arr.push_back(row);
        }
        return arr;
    }
};