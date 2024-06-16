class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
       long long ans=0;
       long long sum=0;
       unordered_map<int,int>freq;
       int start=0;
       int n=nums.size();

       for(int i=0;i<n;i++){
        sum+=(long long)nums[i];
        freq[nums[i]]++;

        while(start<i && freq[nums[i]]>1){
            freq[nums[start]]--;
            sum-=nums[start];
            start++;
        }

        if((i-start+1)==k){
            ans=max(ans,sum);
            freq[nums[start]]--;
            sum-=nums[start];            
            start++;
        }
       }
       return ans; 
    }
};