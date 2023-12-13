class Solution {
    void f(int i,vector<int> &nums,vector<int> & arr,int &ans){
        if(i==nums.size()){
            int val=0;
            for(int i=0;i<arr.size();i++){
             val=val^arr[i];}
            ans+=val;
            return ;}
        arr.push_back(nums[i]);
        f(i+1,nums,arr,ans);
        arr.pop_back();
        f(i+1,nums,arr,ans);
        return ;
    }
public:
    int subsetXORSum(vector<int>& nums) {
        vector<int> arr;
        int ans=0;
        f(0,nums,arr,ans);
        return ans;
    }
};