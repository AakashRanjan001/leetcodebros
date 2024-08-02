
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int k = 0;

        // Count the number of 1s in the array
        for(int num : nums) {
            if(num == 1) k++;
        }

        // If there are no 1s or the array is all 1s, no swaps needed
        if(k == 0 || k == n) return 0;

        // Initialize the number of 0s in the first window of size k
        int current_0s = 0;
        for(int i = 0; i < k; i++) {
            if(nums[i] == 0) current_0s++;
        }

        int min_0s = current_0s;

        // Use sliding window to find the minimum number of 0s in any window of size k
        for(int i = 1; i < n; i++) {
            // Remove the element that is sliding out of the window
            if(nums[i - 1] == 0) current_0s--;
            // Add the element that is sliding into the window
            if(nums[(i + k - 1) % n] == 0) current_0s++;

            // Update the minimum number of 0s found
            if(current_0s < min_0s) min_0s = current_0s;
        }

        return min_0s;
    }
};