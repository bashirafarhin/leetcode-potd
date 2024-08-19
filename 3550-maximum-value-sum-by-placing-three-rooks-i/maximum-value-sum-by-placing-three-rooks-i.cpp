class Solution {
public:
    long long maximumValueSum(vector<vector<int>>& board) {
        int r=board.size();
        int c=board[0].size();
        long long res=LLONG_MIN;
        vector<vector<int>>newBoard(r,vector<int>(3,0));

        for (int i = 0; i < r; i++) {
            vector<pair<int, int>> temp;
            // Creating the pair vector (b, j)
            for (int j = 0; j < c; j++) {
                temp.push_back({board[i][j], j});
            }
            // Sorting in descending order
            sort(temp.begin(), temp.end(), greater<pair<int, int>>());
            // Extracting the indices of the top 3 values
            for (int j = 0; j < 3; j++) {
                newBoard[i][j] = temp[j].second;
            }
        }

        for (int i = 0; i < r ; i++) {
            for (int _i = 0; _i < 3; _i++) {
                for (int j = i + 1; j < r; j++) {
                    for (int _j = 0; _j < 3; _j++) {
                        for (int k = j + 1; k < r; k++) {
                            for (int _k = 0; _k < 3; _k++) {
                                if (newBoard[i][_i] != newBoard[j][_j] && newBoard[j][_j] != newBoard[k][_k] && newBoard[k][_k] != newBoard[i][_i]) {
                                    long long sum = (long long)board[i][newBoard[i][_i]] + (long long)board[j][newBoard[j][_j]] + (long long)board[k][newBoard[k][_k]];
                                    res = max(sum, res);
                                }
                            }
                        }
                    }
                }
            }
        }
        return res;
    }
};