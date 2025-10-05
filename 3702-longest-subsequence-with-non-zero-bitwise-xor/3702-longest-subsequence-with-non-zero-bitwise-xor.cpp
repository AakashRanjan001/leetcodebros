class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
         int n= nums.size();
         int xorSum = 0;
         bool f = true;
         for(int i=0;i<n;i++){
             xorSum = xorSum^nums[i];
             if(nums[i]!=0)f = false;
         }
         if(f == true)return 0;
         return xorSum == 0? nums.size() -1 : nums.size();
    }
};