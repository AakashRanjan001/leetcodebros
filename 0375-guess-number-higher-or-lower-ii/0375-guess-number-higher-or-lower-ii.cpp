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

         dp[start][end] = ans;
        return dp[start][end];
    }
    int solveUsingTab(int n){
        
        //step 1: create the vector array
         vector<vector<int>>dp(n+2 , vector<int>(n+2 , 0));

         //step 2: base case mei toh sab hi zero hai toh kuch karne ki need nhi hai
           //step 3: for loops 
            

            for(int start =n;start>=1;start--){
                for(int end = 1;end<=n;end++){
                    if(start >= end)continue; // agar start is equak to end hai toh woh toh 0 hai na
                    else{
                    int ans = INT_MAX;
                    for(int i=start;i<=end;i++){
                       ans = min(ans , i+max(dp[start][i-1] ,dp[i+1][end]));
                    }
                    
                    dp[start][end] = ans;
                   }
                }
            }   
            return dp[1][n];

    }
    int getMoneyAmount(int n) {
        // int ans = solveUsingRec(1,n);
        // return ans;


        // for optmisation see what all are changing start -----> 1->n
                                                   //end ------> end/n -> 1

        // step1 : create a 2D dp
        // vector<vector<int>>dp(n+1 , vector<int>(n+1 , -1));
        // int ans = solveUsingMem(1 ,n, dp); 
        // return ans;   

        //for TABULATION
      
      
         int ans = solveUsingTab(n);
         return ans;

    }
};