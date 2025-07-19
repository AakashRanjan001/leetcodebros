class Solution {
public:
    // int solve(vector<vector<int>>& grid , int i,int j){
    //      int n = grid.size();
    //      int m = grid[0].size();
    //      if(i>=n || j>=m)return INT_MAX;
    //      if( i == n-1 && j == m-1)return grid[i][j];

    //      int res = grid[i][j] + min(solve(grid,i+1,j) , solve(grid,i,j+1));
    //      return res;
    // }
    

    int memo(vector<vector<int>>& grid , int i,int j,vector<vector<int>>&dp){
      int n = grid.size();
     int m = grid[0].size();
         if(i>=n || j>=m)return INT_MAX;
         if( i == n-1 && j == m-1)return grid[i][j];
         if(dp[i][j]!=-1){
             return dp[i][j];
         }

         dp[i][j] = grid[i][j] + min(memo(grid,i+1,j,dp) , memo(grid,i,j+1,dp));
         return dp[i][j];
    }
    int minPathSum(vector<vector<int>>& grid) {
        //  int ans = solve(grid,0,0);
        //  return ans;

        //APPROACH 2 : using memoization 
        int n = grid.size();
        int m = grid[0].size();
        //step 1: create a dp array
        vector<vector<int>>dp(n ,vector<int>(m ,-1));
        int res = memo(grid,0,0,dp);
        return res;
    }
};