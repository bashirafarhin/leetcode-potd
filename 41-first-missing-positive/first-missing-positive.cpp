class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        vector<int>find(n+1,0);
        for(int i=0;i<n;i++){
            if(1<=nums[i] && nums[i]<=n){
                find[nums[i]]=1;
            }
        }
        
        for(int i=1;i<=n;i++){
            if(find[i]==0){return i;}
        }
        return n+1;
    }
};