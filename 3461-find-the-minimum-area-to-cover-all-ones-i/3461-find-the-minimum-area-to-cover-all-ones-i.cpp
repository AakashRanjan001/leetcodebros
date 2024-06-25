class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
       	int m = grid.size(), n = grid[0].size();
	int topX = INT_MAX, botX = INT_MIN, leftY = INT_MAX, rightY = INT_MIN;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (grid[i][j] == 1) {
				topX = min(topX, i);
				botX = max(botX, i);
				leftY = min(leftY, j);
				rightY = max(rightY, j);
			}
		}
	}
	int area = (botX - topX + 1) * (rightY - leftY + 1);
	return area; 
    }
};