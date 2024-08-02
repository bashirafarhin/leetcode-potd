class Solution {
public:
// TC- O(logn)
    int minPatches(vector<int>& nums, int n) {
        long maxReachable=0;
        int patch=0;
        int i=0;
        while(maxReachable<n){
            if(i>=nums.size() || nums[i]>maxReachable+1){
                maxReachable+=(maxReachable+1);
                patch++;
            } else {
                maxReachable+=nums[i];
                i++;
            }
        }
        return patch;
    }
};