class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        int maxi=*max_element(nums.begin(),nums.end());
        long long ans=0;
        int st=0;
        int count=0;

        for(int i=0;i<n;i++){
           count= nums[i]==maxi ? count+1 : count;
           while(count==k){
            count= nums[st]==maxi ? count-1 : count;
            st++;
            ans+=(n-i);
           }
     
        }
        return ans;

    }
};