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
   int topDownSolve(int n , vector<int>&dp){
        // base case
        if(n == 0 || n == 1){
             return n;
        }
        //step 3: eke aur condition likhna hai 
        if(dp[n]!=-1){ // matlab dp[n] mei kuch value aaya hai 
                          // check if answer already exist 
             return dp[n];
        }
        // function ka naam badalna yaha mai galti karta hu 
        // step two: jo answer hai woh return karoo replace ans with dp[n]
        dp[n] = topDownSolve(n-1,dp) + topDownSolve(n-2,dp);
        return dp[n];
   }
    int fib(int n) {
        //  int ans = getRecSolve(n);
        //  return ans;

//step 1 : Create a DP array
        vector<int>dp(n+1 ,-1);
        int ans = topDownSolve(n,dp);
        return ans;


    }

};