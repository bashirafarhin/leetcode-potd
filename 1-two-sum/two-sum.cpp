class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int start=0;
        int end=nums.size()-1;
        int n=nums.size();
        vector<vector<int>>arr(n,vector<int>(2,0));
        for(int i=0;i<n;i++){
            arr[i]={nums[i], i};
        }
        sort(arr.begin(), arr.end());
        while(start<end){
            int sum = arr[start][0]+arr[end][0];
            if(sum==target){ return {arr[start][1], arr[end][1]}; }
            else if(sum>target){ end--; }
            else{ start++; }
        }
        return {};
    }
};