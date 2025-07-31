class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
         vector<vector<int>>temp = matrix;
         int n= matrix.size();
         int m= matrix[0].size();

         for(int i=0;i<n;i++){ 
            for(int j=0;j<m;j++){
                 temp[j][n-i-1] = matrix[i][j];
            }
         }
         matrix = temp;
    }
};