class Solution 
{
public:
    long long countSubarrays(vector<int>& nums, long long k) 
    {
        // Step 0 : Initialize Pointers and Trackers
        int n = nums.size();
        long long result = 0;
        long long sum = 0;
        
        int i = 0; // left pointer
        int j = 0; // right pointer

        // Step 1: Expand the window with right pointer j
        while (j < n) 
        {
            sum += nums[j];

            // Step 2: Shrink the window from left if the condition is violated
            while (i <= j && sum * (j - i + 1) >= k) 
            {
                sum -= nums[i];
                i++;
            }

            // Step 3: Add the count of valid subarrays ending at j
            result += (j - i + 1);

            j++; // move right pointer forward
        }

        // Step 4: Return the final count
        return result;
    }
};