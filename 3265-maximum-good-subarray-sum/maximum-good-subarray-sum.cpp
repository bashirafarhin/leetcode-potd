class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        vector<long long >prefix(n,0ll);
        prefix[0]=static_cast<long long> (nums[0]);
        for(int i=1;i<n;i++){
            prefix[i]=static_cast<long long> (nums[i]+prefix[i-1] );
        }
        long long int ans=LLONG_MIN;
        
        unordered_map<long long,int> mp;
        
        for(int i=0;i<n;i++){
            if( mp.find(nums[i]-k) != mp.end()){
                 int ind=mp[nums[i]-k];
                 ans = max(ans, prefix[i] - (ind > 0 ? prefix[ind - 1] : 0));
            }
            if( mp.find( nums[i]+k) != mp.end()){
                 int ind=mp[nums[i]+k];
                 ans = max(ans, prefix[i] - (ind > 0 ? prefix[ind - 1] : 0));
            }
            auto it=mp.find(nums[i]);
            if( it== mp.end() || ( prefix[i]-prefix[it->second]<=0 ) ){
                 mp[nums[i]]=i;
            }

            
        }
        return ans==LLONG_MIN ? 0 : ans;
    }
};