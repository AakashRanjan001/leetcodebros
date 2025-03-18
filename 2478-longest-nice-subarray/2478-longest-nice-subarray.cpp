class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {

            int maxLen = 0;
            int n = nums.size();

            for (int i = 0; i < n; i++) {
                int usedBits = 0;
                for (int j = i; j < n; j++) {
                    if ((usedBits & nums[j]) != 0) {
                        break;
                    }
                    usedBits |= nums[j];
                    maxLen = max(maxLen, j - i + 1);
                }
            }

            return maxLen;

    }
};