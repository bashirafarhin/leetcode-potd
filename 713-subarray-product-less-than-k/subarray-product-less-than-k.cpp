class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
       int count=0;
       int curr=0;
       int n=nums.size();
       for(int i=0;i<n;i++){
        curr=1;
        for(int j=i;j<n;j++){
            curr*=nums[j];
            if(curr<k){ count++; }
            if(curr>k){ break; }
        }
       }
       return count;
    }
};