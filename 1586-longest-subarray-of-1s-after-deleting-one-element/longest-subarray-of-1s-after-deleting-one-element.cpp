class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int start=0;
        int n=nums.size();
        int ans=0;
        int count=0;
        for(int end=0;end<n;end++){
            if(nums[end]==0){
                count++;
            }
            while(count>1){
                if(nums[start]==0){ count--; }
                start++;
            }
            ans=max(ans,end-start);
        }
        return ans;
    }
};