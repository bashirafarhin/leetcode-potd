class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int R = matrix.size();
        int C = matrix[0].size();

        // if present in 0th Col or not
        bool isInfirstCol = false;

        // if present in 1st row or not
        bool isInfirstRow = false;

        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                if (r == 0 && matrix[0][c] == 0) {
                    isInfirstRow = true;
                }
                if (c == 0 && matrix[r][0] == 0) {
                    isInfirstCol = true;
                }
                if (matrix[r][c] == 0) {
                    matrix[r][0] = 0;
                    matrix[0][c] = 0;
                }
            }
        }

        for (int r = 1; r < R; r++) {
            if (matrix[r][0] == 0) {
                for (int c = 0; c < C; c++) {
                    matrix[r][c] = 0;
                }
            }
        }

        for (int c = 1; c < C; c++) {
            if (matrix[0][c] == 0) {
                for (int r = 0; r < R; r++) {
                    matrix[r][c] = 0;
                }
            }
        }

        // if 0 present in 0th Col
        if (isInfirstCol) {
            for (int r = 0; r < R; r++) {
                matrix[r][0] = 0;
            }
        }

        // if 0 present in 1st Col
        if (isInfirstRow) {
            for (int c = 0; c < C; c++) {
                matrix[0][c] = 0;
            }
        }
    }
};