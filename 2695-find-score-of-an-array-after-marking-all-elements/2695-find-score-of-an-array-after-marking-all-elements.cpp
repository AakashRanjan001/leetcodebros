
class Solution {
public:
    long long findScore(vector<int>& nums) {
        vector<bool> marked(1e6 + 10, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        for (int i = 0; i < nums.size(); i++) {
            pq.push({nums[i], i});
        }

        long long res = 0;
        while (!pq.empty()) {
            auto p = pq.top();
            pq.pop();
            if (!marked[p.second]) {
                res += p.first;
                marked[p.second] = true;
                int prev = p.second - 1, next = p.second + 1;
                if (prev >= 0) {
                    marked[prev] = true;
                }
                if (next < nums.size()) {
                    marked[next] = true;
                }
            }
        }

        return res;
    }
};