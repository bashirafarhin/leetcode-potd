class Solution {
public:
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
        int n=nums.size();
        vector<long long>ans(n,0);
        unordered_map<int,long long> mp; //id,freq
        set<pair<long long,int>> freqSet; //freq
                
        for(int i=0;i<n;i++){
            if(mp.find(nums[i]) !=mp.end()){
                long long newFreq=mp[nums[i]]+freq[i];
                freqSet.insert( {-1*newFreq,nums[i]} );
                freqSet.erase( {-1*mp[nums[i]],nums[i]} );
                mp[nums[i]]=newFreq;
            } else {
                freqSet.insert( {-1*freq[i],nums[i]} );
                mp[nums[i]]=freq[i];
            }
            ans[i]= freqSet.begin()==freqSet.end() ? 0 : -1*freqSet.begin()->first;
        }
        return ans;
    }
};