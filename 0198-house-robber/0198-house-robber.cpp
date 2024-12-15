class Solution {
public:
   
   

//   // n -> is the index of teh current house 
//     int solveUsingRec(vector<int>& nums , int n){
//         if(n<0)return 0; // agar ek bhi ghar nhi hai toh money = 0
//         if(n == 0){
//              // agar ek hi ghar hai 
//              return nums[0];
//         }
        
//         // include the house 
//         // calling the house which 2 steps behind and also including the money of current house
//          int include = solveUsingRec(nums,n-2) + nums[n]; 
//         // exclude teh house 
//         // means not taking that house means i can take the next adjacent house 
//          int exclude = solveUsingRec(nums,n-1) + 0; 

//          return max(include,exclude);
    
// //     }

//     int solveUsingMem(vector<int>& nums , int n , vector<int>& dp){
//          if(n<0)return 0; 
//         if(n == 0){ 
//              return nums[0];
//         }

// // step 3 : check if the dp[n] already exist or not 
//         if(dp[n]!=INT_MIN){
//              return dp[n];
//         }
        
//         // include the house 
//         // calling the house which 2 steps behind and also including the money of current house
//          int include = solveUsingMem(nums,n-2,dp) + nums[n]; 
//         // exclude teh house 
//         // means not taking that house means i can take the next adjacent house 
//          int exclude = solveUsingMem(nums,n-1,dp) + 0; 

//        //step 2: dp[n] include kar do 
//          dp[n] = max(include,exclude);
//          return dp[n];

//     }

int  solveUsingTab(vector<int>& nums , int n){
     //step 1 : create an array 
     vector<int>dp(n+1 , 0);

     //step 2:base case ko dekho 
     dp[0] = nums[0];

        // in top down moves from n->2 
        ///step 3: 
        for(int i=1;i<=n;i++){
        
        int temp = 0;
            if(i-2>=0)
                temp = dp[i-2];
              int include = temp + nums[i];  
                int exclude = dp[i-1] + 0; 

                dp[i] = max(include,exclude);
            
        }
        return dp[n];
}

    int rob(vector<int>& nums) {
        int n = nums.size()-1; // index of the last house 
        // int ans = solveUsingRec(nums,n);
        // return ans;

        // step 1 : Creating an array 
        // agar size samajh mei nhi aa rha kya rakhna hai tab dekhna ki variable kya hai n yah avary kar rha 
        // as hame array mei store kya kara rhe har ek house ke corresponding maximum money
        // isi kaaran INT_MIN kiya 
        // vector<int>dp(n+1,INT_MIN);
        // int ans = solveUsingMem(nums,n,dp);
        // return ans;




         int ans = solveUsingTab(nums,n);
         return ans;

    }
};