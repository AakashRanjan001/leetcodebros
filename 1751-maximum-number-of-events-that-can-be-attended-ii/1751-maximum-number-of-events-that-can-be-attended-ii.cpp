class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();
        sort(events.begin(), events.end(), [](auto &a, auto &b){ return a[0] < b[0]; });
        vector<int> starts(n), next_idx(n);
        for (int i = 0; i < n; ++i) starts[i] = events[i][0];
        for (int i = 0; i < n; ++i)
            next_idx[i] = upper_bound(starts.begin(), starts.end(), events[i][1]) - starts.begin();
        vector<long long> prev(n+1), curr;
        for (int i = n-1; i >= 0; --i)
            prev[i] = max(prev[i+1], (long long)events[i][2]);
        long long res = prev[0];
        for (int t = 2; t <= k; ++t) {
            curr.assign(n+1, 0);
            for (int i = n-1; i >= 0; --i) {
                long long take = events[i][2];
                int j = next_idx[i];
                if (j <= n) take += prev[j];
                curr[i] = max(curr[i+1], take);
            }
            res = max(res, curr[0]);
            prev.swap(curr);
        }
        return (int)res;
    }
};