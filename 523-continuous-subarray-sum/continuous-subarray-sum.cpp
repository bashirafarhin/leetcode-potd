class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp; //prefixSum
        int i=0,sum=0,n=nums.size();
        mp[0]=-1;
        while(i<n){
            sum+=nums[i];
            int rem=sum%k;

            if (mp.find(rem) !=mp.end() && i-mp[rem]>=2){
                return true;
            }
            if(mp.find(rem)==mp.end()){
                mp[rem]=i;
            }
            i++;
        }
        return false;
    }
};