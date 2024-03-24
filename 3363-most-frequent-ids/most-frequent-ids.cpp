class Solution {
public:
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
        int n=nums.size();
        vector<long long>ans(n,0);
        unordered_map<int,long long> mp; //id,freq
        priority_queue<pair<long long,int>> pq; //freq,id
                
        for(int i=0;i<n;i++){
            mp[nums[i]]+=freq[i];
            while( !pq.empty() && mp[pq.top().second] != pq.top().first ){
                pq.pop();
            }
            pq.push({ mp[nums[i]],nums[i] });
            ans[i]= pq.empty() ? 0 : pq.top().first ;
        }
        return ans;
    }
};