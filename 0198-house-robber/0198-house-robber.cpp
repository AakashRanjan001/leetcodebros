class Solution {
public:
  // n -> is the index of teh current house 
    int solveUsingRec(vector<int>& nums , int n){
        if(n<0)return 0; // agar ek bhi ghar nhi hai toh money = 0
        if(n == 0){
             // agar ek hi ghar hai 
             return nums[0];
        }
        
        // include the house 
        // calling the house which 2 steps behind and also including the money of current house
         int include = solveUsingRec(nums,n-2) + nums[n]; 
        // exclude teh house 
        // means not taking that house means i can take the next adjacent house 
         int exclude = solveUsingRec(nums,n-1) + 0; 

         return max(include,exclude);


    }
    int rob(vector<int>& nums) {
        int n = nums.size()-1; // index of the last house 
        int ans = solveUsingRec(nums,n);
        return ans;
    }
};