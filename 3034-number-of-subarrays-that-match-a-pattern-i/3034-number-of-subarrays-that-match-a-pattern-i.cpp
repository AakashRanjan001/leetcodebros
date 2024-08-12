class Solution {
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        
 
    int n = nums.size();
    int m = pattern.size();
    int count = 0;

    for (int i = 0; i< n-m; ++i) {
        bool Pattern = true;
        for (int k=0; k<m; ++k) {
            
            if ((pattern[k] == 1 && nums[i + k + 1] <= nums[i + k]) ||
                (pattern[k] == 0 && nums[i + k + 1] != nums[i + k]) ||
                (pattern[k] == -1 && nums[i + k + 1] >= nums[i + k])) {
                
                Pattern = false;
                break;
            }
        }

        if (Pattern == true) {
            count++;
        }
    }

    return count;
}
};

























