class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int r = mat.size();
        int c = mat[0].size();
        vector<int> ColPosWhereOneHasOccured(r, -1);
        for (int i = 0; i < r; i++) {
            int cntOfOnes = 0;
            for (int j = 0; j < c; j++) {
                if (mat[i][j] == 1) {
                    if (ColPosWhereOneHasOccured[i] == -1) {
                        ColPosWhereOneHasOccured[i] = j;
                    } else {
                        ColPosWhereOneHasOccured[i] = -1;
                        break;
                    }
                }
            }
        }

        vector<int> RowPosWhereOneHasOccured(c, -1);
        for (int i = 0; i < c; i++) {
            int cntOfOnes = 0;
            for (int j = 0; j < r; j++) {
                if (mat[j][i] == 1) {
                    if (RowPosWhereOneHasOccured[i] == -1) {
                        RowPosWhereOneHasOccured[i] = j;
                    } else {
                        RowPosWhereOneHasOccured[i] = -1;
                        break;
                    }
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < c; i++) {
            if (RowPosWhereOneHasOccured[i] != -1) {
                int pos = RowPosWhereOneHasOccured[i];
                if (ColPosWhereOneHasOccured[pos] != -1) {
                    ans++;
                }
            }
        }
        return ans;
    }
};