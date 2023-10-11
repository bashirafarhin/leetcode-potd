class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
      vector<int> ans;
        vector<int> start;
        vector<int> end;
        for(auto &nums:flowers){
            start.push_back(nums[0]);
            end.push_back(nums[1]);
        }
        sort(start.begin(),start.end());
        sort(end.begin(),end.end());
        for(auto &p:people){
            auto bloombeforeappearanceofpeople= upper_bound(start.begin(),start.end(),p)-start.begin();
            auto deadbeforeappearanceofpeople=lower_bound(end.begin(),end.end(),p)-end.begin();
            ans.push_back(bloombeforeappearanceofpeople-deadbeforeappearanceofpeople);
        }
        return ans;   
    }
};