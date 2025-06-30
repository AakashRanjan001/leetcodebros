class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        map<int, int> mp;
        int maxVal = INT_MIN;
        for (int num : nums) {
            mp[num]++;
            maxVal = max(maxVal, num);
        }
        vector<bool> hash(maxVal + 2, false);

        int cnt = 0;
        for (auto& [num, freq] : mp) {
            if ((num + 1 <= maxVal + 1) && !hash[num + 1] && mp.count(num + 1)) {
                cnt = max(cnt, freq + mp[num + 1]);
                hash[num + 1] = true;
            }
        }

        return cnt;
    }
};
