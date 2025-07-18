typedef long long ll;
class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int sz = nums.size();
        int n = sz / 3;

        vector<ll> left(sz, 0), right(sz, 0);
        priority_queue<int> max_heap;
        ll sum = 0;

        
        for (int i = 0; i < sz; ++i) {
            max_heap.push(nums[i]);
            sum += nums[i];
            if (max_heap.size() > n) {
                sum -= max_heap.top();
                max_heap.pop();
            }
            if (max_heap.size() == n) left[i] = sum;
        }

        priority_queue<int, vector<int>, greater<int>> min_heap;
        sum = 0;

        for (int i = sz - 1; i >= 0; --i) {
            min_heap.push(nums[i]);
            sum += nums[i];
            if (min_heap.size() > n) {
                sum -= min_heap.top();
                min_heap.pop();
            }
            if (min_heap.size() == n) right[i] = sum;
        }

        ll ans = LLONG_MAX;
        for (int i = n - 1; i < 2 * n; ++i) {
            ans = min(ans, left[i] - right[i + 1]);
        }

        return ans;
    }
};
