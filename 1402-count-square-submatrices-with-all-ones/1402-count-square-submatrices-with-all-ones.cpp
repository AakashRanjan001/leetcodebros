// class Solution {
// public:
//     int countSquares(vector<vector<int>>& matrix) {
//         int n = matrix.size();
//         int m = matrix[0].size();
//         int cnt_1 =0;
//         int cnt_2 =0;
//         int cnt_3 =0;

//         for(int i=0;i<n;i++){
//             for(int j=0;j<m;j++){
//                 if(matrix[i][j] == 0){
//                     continue;
//                 }
//                 else if(matrix[i][j] == 1){
//                     cnt_1++;
//                 }
//                 else if(matrix[i][j] == 1 && matrix[i+1][j] ==1 && matrix[i][j+1] == 1 && matrix[i+1][j+1] == 1){
//                     cnt_2++;
//                 }
//                 else{
//                     if(cnt_2 % 4 == 0){
//                         cnt_3++;
//                     }
//                 }

//             }
//         }
//         return cnt_1 + cnt_2 + cnt_3;
//     }
// };

class Solution {
public:
    int countSquares(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int cnt = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i>0 && j>0 && mat[i][j]){
                    mat[i][j] = max(mat[i][j], 1+min({mat[i-1][j],mat[i][j-1],mat[i-1][j-1]}));
                }
                cnt += mat[i][j];
            }
        }
        return cnt;
    }
};

