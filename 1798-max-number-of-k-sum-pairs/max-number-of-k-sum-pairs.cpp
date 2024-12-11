class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int ans=0;
        unordered_map<int,int>mp;
        for(int num : nums){
            if(mp.find(k-num) !=mp.end()){
                mp[k-num]--;
                if(mp[k-num]==0){ mp.erase(k-num); }
                ans++;
            } else{
                mp[num]++;
            }
        }
        return ans;
    }
};