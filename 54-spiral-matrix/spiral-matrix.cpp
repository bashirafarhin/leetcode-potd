class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& m) {
        int r = m.size();
        int c = m[0].size();
        int top = 0;
        int bottom = r - 1;
        int left = 0;
        int right = c - 1;
        vector<int> ans;
        while (!(top > bottom || left > right)) {

            for (int i = left; i <= right; i++) {
                ans.push_back(m[top][i]);
            }

            for (int i = top + 1; i <= bottom - 1; i++) {
                ans.push_back(m[i][right]);
            }

            if (top != bottom) {
                for (int i = right; i >= left; i--) {
                    ans.push_back(m[bottom][i]);
                }
            }

            if (left != right) {
                for (int i = bottom - 1; i >= top + 1; i--) {
                    ans.push_back(m[i][left]);
                }
            }
            top++;
            bottom--;
            left++;
            right--;
        }
        return ans;
    }
};