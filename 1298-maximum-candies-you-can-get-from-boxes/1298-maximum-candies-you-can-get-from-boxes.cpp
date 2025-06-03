const int N = 1000;
bitset<N> canOpen = 0, hasBox = 0;
class Solution {
public:
    int dfs(int i, vector<int>& candies, vector<vector<int>>& keys,
            vector<vector<int>>& containedBoxes) {
        int ans = candies[i];
        for (int k : keys[i]) {
            if (!canOpen[k]) {
                canOpen[k] = 1;
                if (hasBox[k])
                    ans += dfs(k, candies, keys, containedBoxes);
            }
        }
     // what are the adjacent vertices these are the adjacent veryufces j
        for (int j : containedBoxes[i]) {
            hasBox[j] = 1;
            if (canOpen[j])
                ans += dfs(j, candies, keys, containedBoxes);
        }
        return ans;
    }
    int maxCandies(vector<int>& status, vector<int>& candies,
                   vector<vector<int>>& keys,
                   vector<vector<int>>& containedBoxes,
                   vector<int>& initialBoxes) {
        const int n = status.size();   // we have to finmd the 
        hasBox = 0;
        for (int i = 0; i < n; i++) {
            canOpen[i] = status[i];
        }
        int ans = 0;
        for (int i : initialBoxes) {
            hasBox[i] = 1;
            if (canOpen[i])
                ans += dfs(i, candies, keys, containedBoxes);
        }
        return ans;
    }
};