class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> v;
        int n=nums.size();
        int x=pow(2,n);
        for(int i=0;i<x;i++){
            vector<int> vin;
            for(int j=0;j<n;j++){
                if(i & (1<<j)){
                    vin.push_back(nums[j]);
                }
            }
            v.push_back(vin);
        }
        sort(v.begin(),v.end());
        return v;
    }
};