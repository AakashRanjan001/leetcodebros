class Solution {
public: 
     int solve(int n){
         //step 1: create a dp array 
         vector<int>dp(n+1,-1);

         //step 2; base case mei dekho by looking at the top down condition
         dp[0] = 0;
          if( n == 0)return dp[0];
         dp[1] = 1;
          if( n == 1)return dp[1];
        
        
    

         //step 3: itertaive ulta as compared to the memoiszaryion
         for(int i=2;i<=n;i++){
              dp[i] = dp[i-1] + dp[i-2];
         }
         return dp[n];


     }
    // int solve(int n, vector<int>& dp){
    //      if(n ==1 || n==0)return n;

    //      if(dp[n]!=-1)return dp[n];

    //      dp[n] = solve(n-1,dp) + solve(n-2,dp);
    //      return dp[n];
        
    // }
    int fib(int n) {
         // APPROACH1 ----> normal For loop of O(N)
        // if(n == 0|| n==1)return n;
         
        //  int a = 0;
        //  int b  =1;

        //  for(int i = 2;i<=n;i++){
              
        //  int sum = a+b;
        //  a = b;
        //  b = sum;
        //  }
        //  return b;
  

       // APPROACH 2 ---> Recursive Approach O(2^N)
        // if(n ==1 || n ==0)return n;
        // return fib(n-1)+fib(n-2);


        //Approach 3 ---->DP with Memo
        //  vector<int>dp(n+1,-1);
        //  int ans = solve(n,dp);
        //  return ans;


        int ans = solve(n);
        return ans;
    } 

};