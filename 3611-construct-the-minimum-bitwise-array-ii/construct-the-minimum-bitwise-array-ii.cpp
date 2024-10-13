class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n,-1);
        for(int i=0;i<n;i++){
            int num=nums[i];
            int j=0;
            for(;j<32;j++){
                if(!(num & (1<<j))){
                    break;
                } else {
                    num=num ^ (1<<j);
                }
            }

            for(int k=0;k<(1<<j);k++){
                int curr=num | k;
                if((curr | (curr+1))==nums[i]){
                    ans[i]=curr;
                    break;
                }
            }
        }
        return ans;
    }
};