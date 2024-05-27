class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=n;i>=1;i--){
            for(int j=0;j<n;j++){
                if(i<=nums[j]){
                    if(i==n-j){ return i; }
                    break;
                }            
            }
        }
        return -1;
    }
};