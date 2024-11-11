class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>ans;
        for(int i=0;i<intervals.size();i++){
            if(!ans.empty() && ans.back()[1]>=intervals[i][0]){
                vector<int>old=ans.back();
                ans.pop_back();
                ans.push_back({min(old[0],intervals[i][0]),max(old[1],intervals[i][1])});
            } else {
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};