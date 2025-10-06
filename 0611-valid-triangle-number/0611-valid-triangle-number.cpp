class Solution {
public:
    int triangleNumber(vector<int>& nums) {
      // brute force 
      int n = nums.size();
      sort(nums.begin(),nums.end());
      int cnt =0;
      for(int i=0;i<n;i++){
         for(int j=i+1;j<n;j++){
             int sum = nums[i]+nums[j];
             int ind = lower_bound(nums.begin()+j+1,nums.end(),sum) - nums.begin();
             cnt+=(ind-j-1);
         }
      }  // the time complexity is taken to be the O(n^2logn)
      return cnt;
        
    }
};