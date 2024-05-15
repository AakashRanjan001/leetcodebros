int rowOffsets[] = {-1, 0, 1, 0};
int colOffsets[] = {0, 1, 0, -1};

class Solution {
public:
    int safe(int r, int c, vector<pair<int,int>> onePositions) {
        int dist = INT_MAX;
        for (auto it : onePositions) {
            dist = min(dist, (abs(it.first - r) + abs(it.second - c)));
        }
        return dist;
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        if (grid[m - 1][n - 1] == 1 || grid[0][0] == 1) return 0;
        vector<pair<int,int>> onePositions;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    onePositions.push_back({i, j});
                }
            }
        }
        vector<vector<int>> isVisited(m, vector<int>(n, 0));
        isVisited[0][0] = 1;
        int maxSafeness = 0;
        priority_queue<pair<int, pair<int, int>>> safenessQueue;
        safenessQueue.push({safe(0, 0, onePositions), {0, 0}});
        while (!safenessQueue.empty()) {
            int safeness = safenessQueue.top().first;
            int x = safenessQueue.top().second.first;
            int y = safenessQueue.top().second.second;
            safenessQueue.pop();
            if (x == m - 1 && y == n - 1) return safeness;
            for (int k = 0; k < 4; k++) {
                int newRow = x + rowOffsets[k];
                int newCol = y + colOffsets[k];
                if (newRow >= 0 && newCol >= 0 && newRow < m && newCol < n && !grid[newRow][newCol] && !isVisited[newRow][newCol]) {
                    int currentSafeness = min(safe(newRow, newCol, onePositions), safeness);
                    safenessQueue.push({currentSafeness, {newRow, newCol}});
                    isVisited[newRow][newCol] = 1;
                }
            }
        }
        return maxSafeness;
    }
};
