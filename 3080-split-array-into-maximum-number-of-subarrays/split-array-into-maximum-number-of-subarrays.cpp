class Solution {
public:
    int maxSubarrays(vector<int>& nums) {
        int n=nums.size();
        int split=0;
        int curr=nums[0];
        for(int i=0;i<n;i++){
            curr&=nums[i];
            if(curr==0){
                split++;
                if(i+1<n){ curr=nums[i+1]; }
            }
        }
        if(split==0){ return 1; }
        if(curr !=0){ return split; }
        return split;
    }
};