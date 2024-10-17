class Solution {
public:
    //check if square of size mid is valid
    //if valid return number of valid points in it else -1
    int check(int sq, vector<vector<int>>& points, string s) {
        unordered_set<char> st;
        for (int j = 0; j < points.size(); j++) {
            int x = points[j][0];
            int y = points[j][1];
            if (-sq <= x && x <= sq && -sq <= y && y <= sq) {
                if (st.find(s[j]) != st.end()) {
                    return -1;
                }
                st.insert(s[j]);
            }
        }
        return st.size();
    }

    int maxPointsInsideSquare(vector<vector<int>>& points, string s) {
        int maxLength = 0;
        for (auto pt : points) {
            maxLength = max(maxLength, max(abs(pt[0]), abs(pt[1])));
        }
        int low = 0;
        int high = maxLength;
        int ptInValidSq = 0;
        while (low <= high) {
            int mid = (low + high) / 2;
            int pts=check(mid, points, s);
            if (pts !=-1) {
                ptInValidSq=max(ptInValidSq,pts);
                low=mid+1;
            } else {
                high=mid-1;
            }
        }
        return ptInValidSq;
    }
};