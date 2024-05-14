class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int ans=0;
        int n=nums.size();
        int st=0;

        unordered_map<int,int>freq;
        for(int i=0;i<n;i++){
            freq[nums[i]]++;
            while(freq[nums[i]]>k){
                freq[nums[st]]--;
                st++;
            }
            ans=max(ans,i-st+1);
        }
        return ans;
    }
};