class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        int dp[n];
        for(int i = 0; i < n; i++) {
            dp[i] = 1;
        }
        sort(nums.begin(), nums.end());
        unordered_map<int, int> prevIdx;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(nums[i] % nums[j] == 0) {
                    if(dp[i] < 1 + dp[j]) {
                        dp[i] = 1 + dp[j];
                        prevIdx[i] = j;
                    }
                }
            }
        }
        int mxSize = 0;
        int idx = -1;
        for(int i = 0; i < n; i++) {
            if(mxSize < dp[i]) {
                mxSize = dp[i];
                idx = i;
            }
        }
        vector<int> ans(mxSize);
        ans[mxSize - 1] = nums[idx];
        for(int i = mxSize - 2; i >= 0; i--) {
            idx = prevIdx[idx];
            ans[i] = nums[idx];
        }
        return ans;
    }
};