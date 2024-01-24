class Solution {
    int solve(vector<int> &nums,int i){
        if(i==nums.size()){
           for(int num : nums){cout<<num<<" ";}
           cout<<endl;

            return 1;
        }

        int ans=0;
        for(int j=i;j<nums.size();j++){
            
            if( !(nums[j] % (i+1)) || !((i+1) % nums[j]) ) {
             swap(nums[i],nums[j]);
             ans+=solve(nums,i+1);
             swap(nums[i],nums[j]);
            }
            
        }
        return ans;
    }
public:
    int countArrangement(int n) {
        vector<int>nums(n,0);
        for(int i=0;i<n;i++){nums[i]=i+1;}
        return solve(nums,0);
    }
};