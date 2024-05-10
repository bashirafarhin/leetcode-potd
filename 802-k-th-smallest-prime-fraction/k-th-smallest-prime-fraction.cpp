class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n=arr.size();
        vector<pair<float,pair<int,int>>> nums;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                float x=1.0*arr[i]/arr[j];
                nums.push_back({x,{arr[i],arr[j]}});
            }
        }
        sort(nums.begin(),nums.end());
        return {nums[k-1].second.first,nums[k-1].second.second};
    }
};