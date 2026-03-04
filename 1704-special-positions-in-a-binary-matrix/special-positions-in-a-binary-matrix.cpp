class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int r = mat.size();
        int c = mat[0].size();
        int ans = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (mat[i][j] == 1) {
                    int cnt = 0;
                    for (int k = 0; k < r; k++) {
                        cnt += mat[k][j];
                        if (cnt > 1) {
                            break;
                        }
                    }
                    if (cnt == 1) {
                        cnt = 0;
                        for (int k = 0; k < c; k++) {
                            cnt += mat[i][k];
                            if (cnt > 1) {
                                break;
                            }
                        }
                    }

                    if (cnt == 1) {
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};