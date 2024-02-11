                          //khudse nhi bana hai
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        dp.resize(m, vector<vector<int>>(n, vector<int>(n, -1)));
        return helper(0, 0, n - 1, grid);
    }

private:
    int helper(int i, int j1, int j2, vector<vector<int>>& grid) {
        if (i >= m || j1 >= n || j1 < 0 || j2 >= n || j2 < 0) {
            return 0;
        }
        if (dp[i][j1][j2] != -1) {
            return dp[i][j1][j2];
        }

        int res = grid[i][j1] + grid[i][j2];
        if (j1 == j2) {
            res -= grid[i][j1];
        }

        vector<int> nums{
            helper(i + 1, j1 - 1, j2 - 1, grid),
            helper(i + 1, j1 - 1, j2, grid),
            helper(i + 1, j1 - 1, j2 + 1, grid),

            helper(i + 1, j1, j2 - 1, grid),
            helper(i + 1, j1, j2, grid),
            helper(i + 1, j1, j2 + 1, grid),

            helper(i + 1, j1 + 1, j2 - 1, grid),
            helper(i + 1, j1 + 1, j2, grid),
            helper(i + 1, j1 + 1, j2 + 1, grid)
        };
        int tmp = *max_element(nums.begin(), nums.end());

        return dp[i][j1][j2] = tmp + res;
    }

private:
    vector<vector<vector<int>>> dp;
    int m = 0;
    int n = 0;
};