class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        vector<vector<int>> ans = matrix;  // Initialize ans with same dimensions

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(matrix[i][j] == 0) {
                    for(int k = 0; k < m; k++) { // row wise apon zero daal rhe 
                        ans[i][k] = 0;
                    }
                    for(int k = 0; k < n; k++) { // col wiae apon zero daal rhe 
                        ans[k][j] = 0;
                    }
                }
            }
        }

        matrix = ans;
    }
};
