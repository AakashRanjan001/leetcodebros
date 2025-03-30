class Solution {
public:
    vector<int> minCosts(vector<int>& cost) {
        
     vector<int> temp = cost;
        vector<int> ans;
        ans.push_back(cost[0]);
        int n = cost.size();

        for (int i = 1; i < n; i++) {
            if (cost[i] < ans[i - 1]) {
                ans.push_back(cost[i]);
            } else {
                ans.push_back(ans[i - 1]);
            }
        }
        return ans;
    }
};