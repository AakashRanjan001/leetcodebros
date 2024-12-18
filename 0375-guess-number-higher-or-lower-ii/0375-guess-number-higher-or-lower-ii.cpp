class Solution {
public:
    int solveUsingRec(int start , int end){
         //base case 
          if(start>=end){ //koi valid number nhi hai ya toh ek hi number hai 
             return 0;     // agr ek hi number hai toh koi penalty nhi lagegi number pakka sahi guess hoga
          }

          int ans = INT_MAX;
          for(int i=start;i<=end;i++){
            // harr ek i ko try karke uska answer nikala aur uska mininmum find outkar liya 
             ans = min(ans , i+max(solveUsingRec(start,i-1) ,solveUsingRec(i+1 ,end)));
          }

       return ans;
    }

    int solveUsingMem(int start , int end , vector<vector<int>>&dp){
          if(start>=end){ //koi valid number nhi hai ya toh ek hi number hai 
             return 0;     // agr ek hi number hai toh koi penalty nhi lagegi number pakka sahi guess hoga
          }

//step 3: check if answer already exists or not 
 if(dp[start][end]!=-1){
     return dp[start][end];
 }

//step 2: ans ko dp array mei chabnge kar do
          int ans = INT_MAX;
          for(int i=start;i<=end;i++){
            // harr ek i ko try karke uska answer nikala aur uska mininmum find outkar liya 
             ans = min(ans , i+max(solveUsingMem(start,i-1,dp) ,solveUsingMem(i+1 ,end,dp)));
          }

       return  dp[start][end] =ans;
    }
    int getMoneyAmount(int n) {
        // int ans = solveUsingRec(1,n);
        // return ans;


        // for optmisation see what all are changing start -----> 1->n
                                                   //end ------> end/n -> 1

        // step1 : create a 2D dp
        vector<vector<int>>dp(n+1 , vector<int>(n+1 , -1));
        int ans = solveUsingMem(1 ,n, dp); 
        return ans;                                          
    }
};