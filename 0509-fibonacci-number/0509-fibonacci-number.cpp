class Solution { // Recursive solution 
public:
//    int getRecSolve(int n){
//        // base case
//         if(n == 0 || n==1){
//              return n;
//         }
//         int ans = getRecSolve(n-1) + getRecSolve(n-2);
//         return ans;
//    }
//    int topDownSolve(int n , vector<int>&dp){
//         // base case
//         if(n == 0 || n == 1){
//              return n;
//         }
//         //step 3: eke aur condition likhna hai 
//         if(dp[n]!=-1){ // matlab dp[n] mei kuch value aaya hai 
//                           // check if answer already exist 
//              return dp[n];
//         } 
//         // function ka naam badalna yaha mai galti karta hu 
//         // step two: jo answer hai woh return karoo replace ans with dp[n]
//         dp[n] = topDownSolve(n-1,dp) + topDownSolve(n-2,dp);
//         return dp[n];
//    }
    // int bottomUpSolve(int n){
    //      // step 1:
    //       // creat ea DP array
    //       vector<int>dp(n+1 , -1);

    //       // step 2:base casejo tumne top down mei likha tha usko upgrade karo
    //       dp[0] = 0;
    //       if(n==0)return dp[0];
    //       dp[1] = 1;
    //       if(n==1)return dp[1];

    //       //step 3: 
    //       // perform the iterative approach // ulta as chalenge of top down
    //       for(int i=2;i<=n;i++){
    //          dp[i] = dp[i-1] + dp[i-2];
    //       }
    //       return dp[n];

    // }
    int spaceOptSolve(int n){
         
         //step2: base case
         int prev2 =0;
         int prev1 =1 ;

// yaha mei galti hui
      if(n==0)return prev2;
      if(n==1)return prev1;

         int curr;
         for(int i=2;i<=n;i++){
             curr = prev2 + prev1;
             prev2 = prev1;
             prev1 = curr;
         }
         return curr;
    }

   
    int fib(int n) {
    //  return bottomUpSolve(n);
    return spaceOptSolve(n);
     

    }

};