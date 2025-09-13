class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int u=0;
        for(int i=0;i<n;i++){
            if(nums[u] !=nums[i]){
                u++;
                nums[u]=nums[i];
            }
        }
        return ++u;
    }
};