class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
         int n = nums.size();
         // O(N)mei toh answer Brute toh pata chal jayega 
         if(n == 1)return nums[0];
         for(int i=0;i<n;i++){
             if(i == 0){
                 if(nums[i]!=nums[i+1])return nums[i];
             }
             else if(i == n-1){
                 if(nums[i]!= nums[i-1])return nums[i];
             }
             else{
                 if(nums[i]!=nums[i+1] && nums[i]!=nums[i-1]){
                     return nums[i];
                 }
             }
         }
         return 0;

    }
};