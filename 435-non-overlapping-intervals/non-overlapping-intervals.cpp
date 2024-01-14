class Solution {
// bool operator()(vector<int>v1,vector<int>v2){
//       if(v1[1]<v2[1]){
//           return true;
//       }
//       if(v1[1]==v2[1]){
//           return v1[0]<v2[0]? true : false ;
//       }
//       return false;
//     }

public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        int count=0;
        int l=intervals[0][0];
        int h=intervals[0][1];
        int i=1;

        while(i<n){
         if( intervals[i][0]<h ){
          count++;
          h=min(h,intervals[i][1]);
          }
          else {
            l=intervals[i][0];
            h=intervals[i][1];
          }
          i++;
        }
        return count;
    }
};