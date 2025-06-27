class Solution {
public:
    int findPeakElement(vector<int>& nums) {
         // Brute toh O(n) solution toh ho jayega
         int n = nums.size();
         for(int i=0;i<n;i++){
             if((i == 0 || nums[i]>nums[i-1]) && (i == n-1 || nums[i]>nums[i+1])){
                 return i;
             }
         }
         return 0;
    }
};