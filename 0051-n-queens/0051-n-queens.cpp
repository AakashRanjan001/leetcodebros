class Solution {
public:

   bool isSafe(int row,int col,vector<string>&board, int n){
            int duprow = row;
            int dupcol = col; 
            // to check the upper diagonal'
            while(row>=0 && col>=0){
                 if(board[row][col] == 'Q')return false;
                 row--;
                 col--;
            }

            col = dupcol;
            row = duprow;

            // to chcek the left 
            while(col>=0){
                 if(board[row][col] == 'Q')return false;
                 col--;
            }

            row = duprow;
            col = dupcol;

            // to check the lower diagnal
            while(row<n && col>=0){
                 if(board[row][col] =='Q')return false;
                 row++;
                 col--;
            }
            // agar maanlo kahi dikkat nhi aayi then badhiya hai we then retyirn true
            return true;

   }
   void solve(int col,vector<string>& board, vector<vector<string>>& ans,int n){
         if(col == n){
             ans.push_back(board);
             return;
         }

         for(int row = 0;row<n;row++){
             if(isSafe(row,col,board,n)){
                 board[row][col] = 'Q';
                 solve(col+1,board,ans,n);
                 board[row][col] = '.';// backtarcking 
             }
         }
   }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n);
        string s(n,'.'); 
        for(int i=0;i<n;i++){
             board[i] = s;
        }

        solve(0,board,ans,n); // here i am taking the column as '0'
        return ans;
    }
};