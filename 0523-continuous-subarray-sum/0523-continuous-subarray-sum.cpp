class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        // for (int i = 0; i < n; ++i) {
        //     nums[i] = nums[i] % k;
        // }

        unordered_map<int, int> mp;
        mp[0] = -1;
        int sum = 0;

        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            sum%=k;
            if (mp.count(sum)) {
                if (i - mp[sum] > 1)
                    return true;
            } else {
                mp[sum] = i;
            }
        }

        return false;
    }
};
