class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n=nums.size();
        int l=1<<n;
        int ans=0;
        for(int i=1;i<l;i++){
            int num=i;
            int curr=0;
            int m=n-1;
            while(num>0){
                if(num & 1){
                 curr=curr^nums[m];
                }
                num=num>>1;
                m--;
            }
            ans+=curr;
        }
        return ans;
    }
};