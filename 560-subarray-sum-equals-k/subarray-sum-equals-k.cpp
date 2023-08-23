class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
     int curr_sum = 0,count=0;
     int n=nums.size();
     unordered_map<int,int> map;
     for (int i = 0; i < n; i++) {
        curr_sum = curr_sum + nums[i];
        if (curr_sum == k) {
           count++;
        }
        if (map.find(curr_sum - k) != map.end()) {
           count+=map[curr_sum-k];
        }
        map[curr_sum]++;
     }
     return count;}
};