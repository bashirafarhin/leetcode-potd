class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){ mp[nums[i]]=1; }
        int ans=0;
        for(int i=0;i<n;i++){
            if(mp.find(nums[i]+1)==mp.end()){
                int l=1;
                int val=nums[i]-1;
                while(mp.find(val) !=mp.end()){
                    val--;
                    l++;
                }
                ans=max(ans,l);
            }
        }
        return ans;
    }
};