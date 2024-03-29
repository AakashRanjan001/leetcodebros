class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        const int n = nums.size();
        long long ans = 0;
        int maxNum = *max_element(nums.begin(), nums.end());
        int freq = 0;
        int limit = 0;
        int right = 0;

    
        while(right < n) {
            if(nums[right] == maxNum) freq++;
            if(freq == k) break;
            right++;
        }

        
        if(freq < k) return 0;

        
        while(right < n) {
            bool found = false;
            if(nums[right] == maxNum) {
                found = true;
            }

            
            if(found) {
                while(limit < right && nums[limit] != maxNum) {
                    limit++;
                }
                limit++;
            }
            
        
            ans += limit;
            right++;   
        }

        return ans;
    }
};
