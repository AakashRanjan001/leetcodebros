class Solution {
public:
    int solveUsingRec(vector<int>& piles,int i,int M ,int Alice){
         if(i == piles.size())return 0;

         // mujhe maximise karna hai zlice ke piles of stones ko
         int ans = Alice ? INT_MIN:INT_MAX;
         // agar Alice ki turen hai toh INT_MIN nhi toh INT_MAX for BOb
         int total =0;

         for(int X=1;X<=2*M ;X++){
            if(i+X-1 >= piles.size())break;
             total+=piles[i+X-1];
            // if alice ki turn hai 
            if(Alice)
             ans = max(ans , total + solveUsingRec(piles,i+X,max(X,M),!Alice));
            else
             // bob ki turn hai hame bob ka piles of stones kam karna hai 
             // hame bob ke case mei total no.of stones kitne hai wo nhi nikalna hai toh uss case mei total ko add nhi karenge 
             ans = min(ans , solveUsingRec(piles,i+X,max(X,M),!Alice));

         }
         return ans;
    }
    int solveUsingmem(vector<int>& piles,int i,int M ,int Alice,vector<vector<vector<int>>>&dp){
         if(i == piles.size())return 0;

         if(dp[i][M][Alice]!=-1){
             return dp[i][M][Alice];
         }

         // mujhe maximise karna hai zlice ke piles of stones ko
         int ans = Alice ? INT_MIN:INT_MAX;
         // agar Alice ki turen hai toh INT_MIN nhi toh INT_MAX for BOb
         int total =0;

         for(int X=1;X<=2*M ;X++){
            if(i+X-1 >= piles.size())break;
             total+=piles[i+X-1];
            // if alice ki turn hai 
            if(Alice)
             ans = max(ans , total + solveUsingmem(piles,i+X,max(X,M),!Alice,dp));
            else
             // bob ki turn hai hame bob ka piles of stones kam karna hai 
             // hame bob ke case mei total no.of stones kitne hai wo nhi nikalna hai toh uss case mei total ko add nhi karenge 
             ans = min(ans , solveUsingmem(piles,i+X,max(X,M),!Alice,dp));

         }
         return dp[i][M][Alice] =  ans;
    }

    int stoneGameII(vector<int>& piles) {
         
         //starting the index from 0 and the M ---> 1 and the turn is Alice is marked as true
        // int ans = solveUsingRec(piles,0,1,true);
        // return ans;
        
        //step 1: create a Dp array 
         vector<vector<vector<int>>>dp(piles.size()+1,vector<vector<int>>(piles.size()+1 , vector<int>(2,-1)));
        int ans = solveUsingmem(piles,0,1,true,dp);
        return ans;
    }
};