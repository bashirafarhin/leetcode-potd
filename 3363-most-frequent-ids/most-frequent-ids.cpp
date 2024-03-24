class Solution {
public:
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
        int n=nums.size();
        vector<long long>ans(n,0);
        unordered_map<int,long long> mp; //id,freq
        set<pair<long long,int>> freqSet; //freq
                
        for(int i=0;i<n;i++){
            long long oldFreq=0;
            int id=nums[i];
            if(mp.find(id) !=mp.end()){
                oldFreq=mp[id];
                freqSet.erase({-1*oldFreq,id});
            }
            long long newFreq= oldFreq + freq[i];
            freqSet.insert( {-1*newFreq,id} );
            mp[id]=newFreq;

            ans[i]= freqSet.begin()==freqSet.end() ? 0 : -1*freqSet.begin()->first;
        }
        return ans;
    }
};