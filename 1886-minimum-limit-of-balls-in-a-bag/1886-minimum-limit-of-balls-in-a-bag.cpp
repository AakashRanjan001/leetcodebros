 // Not solver by me, need to solve agian a nice intutiyion]
 
class Solution {
public:
    int minimumSize(vector<int>& nums, int maxSplits) {
        int left = 1, right = *max_element(nums.begin(), nums.end()); 
        while (left < right) {
            int mid = left + (right - left) / 2;
            long long splitsNeeded = 0;
            for (int num : nums) {
                splitsNeeded += (num - 1) / mid;
            }
            if (splitsNeeded <= maxSplits) {
                right = mid;
            } 
            else {
                left = mid + 1;
            }
        }
        return left;
    }
};