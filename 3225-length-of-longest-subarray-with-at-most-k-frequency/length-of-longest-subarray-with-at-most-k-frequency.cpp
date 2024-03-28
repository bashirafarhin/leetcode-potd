class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int>freq;
        int n=nums.size();
        int ans=0;
        int start=0;
        for(int i=0;i<n;i++){
            freq[nums[i]]++;
            if( freq[nums[i]]>k ){
              int num=nums[i];
              while(freq[num]>k){
                freq[nums[start]]--;
                start++;
              }
            }
            ans=max(ans,i-start+1);
        }
        return ans;
    }
};