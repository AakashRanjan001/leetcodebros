
class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        
        int  mn = nums[0], mx = nums[0], temp = 0;
        long long ans = 0; 
        for(int i = 0; i < nums.size(); i++) {
            
            // Update the min and max of the current window
            mn = min(mn, nums[i]);
            mx = max(mx, nums[i]);

            // Shrink the window if the condition is violated
            while(mx - mn > 2) {

                // Move the start of the window
                temp++;

                mn = nums[temp];
                mx = nums[temp];

                // Recompute min and max for the current window
                for(int j = temp; j <= i; j++) {
                    mn = min(mn, nums[j]);
                    mx = max(mx, nums[j]);
                }
            }

            // Add the number of subarrays ending at index i
            ans += (i - temp + 1);
        }

        return ans;
    }
};