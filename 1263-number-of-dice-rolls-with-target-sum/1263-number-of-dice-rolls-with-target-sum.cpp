
class Solution {
public:
   long long int MOD = 1e9 +7;
   int solveUsingRec(int n , int k , int target){
     //base case
     if(n<0)return 0;
     if(n==0 && target ==0)return 1;
     if(n==0 && target!=0)return 0;
     if(n!=0 && target == 0)return 0;
 
      int ans =0;
       for(int i=1;i<=k;i++){
          ans += solveUsingRec(n-1,k,target - i);
       }
       return ans;
   }
    long long int  solveUsingMem( long long int  n, long long int  k, long long int  target ,vector<vector< long long int >>&dp){
       //base case
     if(n<0)return 0;
     if(n==0 && target ==0)return 1;
     if(n==0 && target!=0)return 0;
     if(n!=0 && target == 0)return 0;
     //step 3: check if the answer prexists or not
      if(dp[n][target]!=-1){
         return dp[n][target];
      }
 
       long long int  ans =0;
      //step 2: change the answer to dp array
       for(int i=1;i<=k;i++){
        long long int recAns = 0;
        if(target-i>=0)
           recAns = solveUsingMem(n-1,k,target - i,dp);
           recAns = recAns%MOD;
           ans = ans%MOD;
           ans = (ans + recAns)% MOD;
            
       }
       dp[n][target] = ans;
       return dp[n][target];
   }

   int solveUsingTab(int n , int k, int target){
   // step 1: create a 2D array
    vector<vector<int >>dp(n+1 , vector<int >(target+1 ,0));

    //step 2: base case mei dekho 
    dp[0][0] = 1;

      // to down mei n->0 and target->0
    //step 3: iterative array  
    for(int index =1;index<=n;index++){
         for(int t=1;t<=target;t++){
               long long int  ans =0;
     
     
       for(int i=1;i<=k;i++){
        long long int recAns = 0;
        if(t-i>=0 && index -1>=0)
           recAns = dp[index-1][t - i];
           recAns = recAns%MOD;
           ans = ans%MOD;
           ans = (ans + recAns)% MOD;      
       }
       dp[index][t] = ans;
     
         }  
    }
  return dp[n][target];
   }
    int numRollsToTarget(int n, int k, int target) {
        // int ans = solveUsingRec(n,k,target);
        // return ans;

        //here also two varuables are changing they are n , target
        //step 1: create a 2D array
        // vector<vector<int >>dp(n+1 , vector<int >(target+1 ,-1));
        // long long int ans = solveUsingMem(n,k,target,dp);
        // return ans;

// tabulation 
     int ans = solveUsingTab(n,k,target);
     return ans;




    }




};