class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int ts=n*(n+1)/2;
        return ts-accumulate(nums.begin(),nums.end(),0);
    }
};