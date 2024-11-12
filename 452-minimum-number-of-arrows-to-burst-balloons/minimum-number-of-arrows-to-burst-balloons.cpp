class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int n=points.size();
        int arrows=1;
        int left=points[0][0];
        int right=points[0][1];
        for(int i=1;i<n;i++){
            if(right>=points[i][0]){
                left=max(left,points[i][0]);
                right=min(right,points[i][1]);
            } else {
                left=points[i][0];
                right=max(right,points[i][1]);
                arrows++;
            }
        }
        return arrows;
    }
};