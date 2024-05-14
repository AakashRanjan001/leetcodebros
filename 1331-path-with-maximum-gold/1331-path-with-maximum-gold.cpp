class Solution {
public:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    
    int f(vector<vector<int>>& grid, int i, int j) {
        int gold = grid[i][j];  
        int curr=grid[i][j];
        grid[i][j]=0;
        for (int k = 0; k < 4; k++) {  
            int row = i + dx[k];       
            int col = j + dy[k];      
            
            if (row >= 0 && row < grid.size() && col >= 0 && col < grid[0].size() && grid[row][col] != 0) {
                gold = max(gold, curr + f(grid, row, col));  
            }
        }
        grid[i][j]=curr;
        
        return gold;  
    }
    
    int getMaximumGold(vector<vector<int>>& grid) {
        int ans = 0;
        
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] != 0) {
                  ans = max(ans, f(grid, i, j));
                     
                }
            }
        }
        
        return ans;
    }
};
