
class Solution {
public:
    Solution() {
       ios_base::sync_with_stdio(false);
       cin.tie(nullptr);
       cout.tie(nullptr);
    }
    int n, m;
    bool ok;
    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};
    bool valid(int i, int j) {
       return i >= 0 && j >= 0 && i < n && j < m;
    }
    void dfs(int i, int j, vector<vector<int>> &grid1, vector<vector<int>> &grid2) {
       grid2[i][j] = 0;
       for (int k = 0; k < 4; ++k) {
          int nx = i + dx[k], ny = j + dy[k];
          if (valid(nx, ny) && grid2[nx][ny]) ok &= grid1[nx][ny], dfs(nx, ny, grid1, grid2);
       }
    }
    int countSubIslands(vector<vector<int>> &grid1, vector<vector<int>> &grid2) {
       n = (int) grid2.size(), m = (int) grid2[0].size();
       int ans = 0;
       for (int i = 0; i < n; ++i)
          for (int j = 0; j < m; ++j)
             if (grid2[i][j] && grid1[i][j])
                ok = true, dfs(i, j, grid1, grid2), ans += ok;
       return ans;
    }
};