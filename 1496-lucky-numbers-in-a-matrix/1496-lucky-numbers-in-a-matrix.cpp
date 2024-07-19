
class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        
        vector<int> minRow(n, INT_MAX);
        vector<int> maxCol(m, INT_MIN);
        vector<int> res;


        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] < minRow[i]) {
                    minRow[i] = matrix[i][j];
                }
            }
        }
        for (int j = 0; j < m; j++) {
            for (int i = 0; i < n; i++) {
                if (matrix[i][j] > maxCol[j]) {
                    maxCol[j] = matrix[i][j];
                }
            }
        }

        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == minRow[i] && matrix[i][j] == maxCol[j]) {
                    res.push_back(matrix[i][j]);
                }
            }
        }

        return res;
    }
};
