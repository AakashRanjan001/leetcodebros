class Solution {
public:
    bool isvalidBoard(vector<vector<char>>& board,int row,int col,char c){
         for(int i=0;i<9;i++){
             if(board[i][col] == c){
                 return false; // matlab agar ek particular column mei phele se wahi character hai
             }
             if(board[row][i] == c){ // same row
                 return false;
             }
             if(board[3* (row/3) + i/3][3*(col/3) + i%3] == c){
                 return false; // already present in the entire 3*3 matrix 
             }
         }
         return true;
    }
    bool solve(vector<vector<char>>& board){
          for(int i=0;i<board.size();i++){
             for(int j=0;j<board[0].size();j++){
                 if(board[i][j] == '.'){
                     for(char c = '1';c<='9';c++){
                         if(isvalidBoard(board,i,j,c)){
                             board[i][j] = c;

                             if(solve(board) == true)return true;
                             else board[i][j] = '.';
                         }
                     }
                     return false;// if we could nt place any of the 1-9 numbers in the range , and hence we return false 
                 }
             }
          }
          return true; // the base case where i need not to fill any more items and hence we have filld the sudoku whole 
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};