class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size();
        int maxC=0;
        int currC=0;
        for(int i=0;i<n;i++){
            if(nums[i]==1){ currC++; }
            else { currC=0; }
            maxC=max(maxC, currC);
        }
        return maxC;
    }
};