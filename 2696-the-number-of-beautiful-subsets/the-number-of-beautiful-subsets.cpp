class Solution {
public:
    int solve(vector<int>& nums, int i,int k,unordered_map<int,int>&mp){
        if(i==nums.size()){
            if(mp.size()==0){ return 0; }
            return 1;
        }
        int ans=solve(nums,i+1,k,mp);

        if(!mp[nums[i]-k]){
            mp[nums[i]]++;
            ans+=solve(nums,i+1,k,mp);
            mp[nums[i]]--;
        }
        return ans;
    }

    int beautifulSubsets(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        unordered_map<int,int>mp;
        return solve(nums,0,k,mp);
    }
};