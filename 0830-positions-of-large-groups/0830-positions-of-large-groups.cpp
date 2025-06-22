class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        int i = 0;
        int n = s.size();
        vector<vector<int>> ans;

        for (int j = 1; j <= n; j++) {
            if (j == n || s[i] != s[j]) {
                if (j - i >= 3) {
                    ans.push_back({i, j - 1});
                }
                i = j;
            }
        }
        return ans;
    }
};
