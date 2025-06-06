class Solution {
    static bool comp(vector<int>& a, vector<int>& b) {
    return a[1] < b[1];
}
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), comp);
        int ans = 0;
        // int left = points[0][0];
        int right = points[0][1];
        for (int i = 1; i < points.size(); i++) {
            if (right >= points[i][0]) {
                ans++;
            } else {
                // left = min(left, points[i][0]);
                right = points[i][1];
            }
        }
        return points.size()-ans;
    }
};