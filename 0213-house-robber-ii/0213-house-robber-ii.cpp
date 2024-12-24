class Solution {
public:
    int solveUsingRec(vector<int> &nums , int n){
        // base case
        if(n<0)return 0;
        if(n==0)return nums[0];

        // include
        int include = nums[n] + solveUsingRec(nums,n-2);
        int exclude = 0 + solveUsingRec(nums,n-1);

        int ans = max(include,exclude);
        return ans;   

    }
    int solveUsingMem(vector<int>& nums, int n ,  vector<int>&dp){
          if(n<0)return 0;
        if(n==0)return nums[0];
        //step 3: check answer already exists
         if(dp[n]!=INT_MIN){
             return dp[n];
         }


        // include // step 2: convert the answer into the dp array
        int include = nums[n] + solveUsingMem(nums,n-2,dp);
        //exclude
        int exclude = 0 + solveUsingMem(nums,n-1,dp);

        int ans = max(include,exclude);
        dp[n] = ans;
        return dp[n]; 

    }
    
    int rob(vector<int>& nums) {
        int n = nums.size()-1; // n --> last index 
   
        vector<int>temp1,temp2;
        for(int i=0;i<=n;i++){
            if(i!=0)temp1.push_back(nums[i]);// not considering the first elemnet
            if(i!=n)temp2.push_back(nums[i]);// not considering the las element
        }
   
        // int ans = max(solveUsingRec(temp1,n-1) , solveUsingRec(temp2,n-1));
        // // n-1 isisliye kiye taaki last index ek kam ho jayega as ek elemnt kam kiye hai
        // return ans;

             //step 1: create a dp array 
        vector<int>dp1(n+1 , INT_MIN);
        vector<int>dp2(n+1 , INT_MIN);
        int ans = max(solveUsingMem(temp1,n-1,dp1),solveUsingMem(temp2,n-1,dp2));
        return ans;
    }
};