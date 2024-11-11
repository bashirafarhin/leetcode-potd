class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n=intervals.size();
        int ind=n;
        for(int i=0;i<n;i++){
            if(intervals[i][0]>newInterval[0]){
                ind=i;
                break;
            }
        }
        intervals.insert(intervals.begin()+ind,newInterval);
        vector<vector<int>>ans;
        for(int i=0;i<n+1;i++){
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