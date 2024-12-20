class Solution {
public:
    int solveUsingRec(vector<int>& nums , int curr, int prev){
         // base cas e
         if(curr>=nums.size()){
            return 0;
         }
         // include 2 case smei karna hai 
        // 1. agar ans array empty hai  
        // 2. agar array mei element hai aur arr[curr]> arr[prev] wla 
         // include  prev == -1 means  ans array empty hai aur mujhe bass include karna hai
          int include =0;
          if(prev == -1 || nums[curr]>nums[prev]){
             include = 1 + solveUsingRec(nums,curr+1, curr);
             //curr ko aage badahana hai aur prev ko curr ke jagah
          }
  
         // excude 
         int exclude = 0 + solveUsingRec(nums,curr+1 , prev);
         // prev ko kuch nhi karna hai woh aage nhi badhega
         int ans = max(include, exclude);
         return ans;
    }
    int solveUsingMem(vector<int>& nums, int curr, int prev , vector<vector<int>>&dp){
         if(curr>=nums.size()){
            return 0;
         }
         int new_prev = prev +1 ;
         // step 3: just after th base case check if the value already exisd
         if(dp[curr][new_prev ]!=-1){
             return dp[curr][new_prev ];
         }


         // step 2: nswer mei dp array ka us ekaro
         int include =0;
          if(prev == -1 || nums[curr]>nums[prev]){
             include = 1 + solveUsingMem(nums,curr+1, curr,dp);
             //curr ko aage badahana hai aur prev ko curr ke jagah
          }
  
         // excude 
         int exclude = 0 + solveUsingMem(nums,curr+1 , prev,dp);
         // prev ko kuch nhi karna hai woh aage nhi badhega
         int ans = max(include, exclude);
         dp[curr][new_prev ] =ans;
         return dp[curr][new_prev ];
    }

    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        int curr =0;
        int prev = -1 ; // ye index isiluye liye ki jab include karenge tab apon ko compare karna hoga na last element ko current element se 
        // int ans = solveUsingRec(nums,curr, prev);
        // return ans;
          // size of rows moves from 0->n-1 => n rows
           // columns = -1--> n-1 => n+1 cols
       // step 1 : create a dp array 
       vector<vector<int>>dp(n, vector<int>(n+1 , -1));
        int ans = solveUsingMem(nums,curr, prev , dp);
        return ans;
    }
};