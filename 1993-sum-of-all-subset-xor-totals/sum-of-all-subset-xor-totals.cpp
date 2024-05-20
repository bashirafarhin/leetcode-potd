class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        int len=1<<n;
        for(int i=0;i<len;i++){
            int num=i;
            int curr=0;
            for(int j=n-1;j>=0;j--){
                if(num & 1) curr=curr ^ nums[j];
                num>>=1;
            }
            ans+=curr;
        }
        return ans;
    }
};