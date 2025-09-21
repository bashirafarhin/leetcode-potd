class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();

        sort(intervals.begin(), intervals.end());
        int prev=0;
        vector<vector<int>>ans={{intervals[0][0],intervals[0][1]}};
        for(int i=1;i<n;i++){
            if(ans[prev][1]>=intervals[i][0]){
                ans[prev][1]=max(ans[prev][1],intervals[i][1]);
            } else {
                ans.push_back(intervals[i]);
                prev++;
            }
        }
        return ans;
    }
};