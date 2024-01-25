
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n));
        int sRow = 0, eRow = n-1, sCol = 0, eCol = n-1;
        int count = 0, total = n*n, temp = 1;
        while(temp <= total){

            for(int i=sCol; i<=eCol; i++){
                ans[sRow][i] = temp++;
            }
            sRow++;

            for(int i=sRow; i<=eRow; i++){
                ans[i][eCol] = temp++;
            }
            eCol--;

            for(int i=eCol; i>=sCol; i--){
                ans[eRow][i] = temp++;
            }
            eRow--;

            for(int i=eRow; i>=sRow; i--){
                ans[i][sCol] = temp++;
            }
            sCol++;

        }

        return ans;
    }
};