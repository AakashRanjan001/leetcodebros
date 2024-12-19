class Solution {
public:
    int solveUsingRec(string a , string b , int i , int j){
         //base case 
         if(i == a.length())return 0;
         if(j == b.length())return 0;// jab donoo end of the string aa gye tab rukna hai

         //if char match 
         int ans =0;
         if(a[i] == b[j]){
             ans = 1 + solveUsingRec(a,b,i+1,j+1);
             // match hu toh curr char ko toh include karenge phir baaki recursion kaerga 
         }
         else{
             ans =  0 + max(solveUsingRec(a,b,i,j+1) , solveUsingRec(a,b,i+1,j));
         }
         return ans;
    }
    int solveUsingMem(string &a , string &b , int i , int j,  vector<vector<int>>&dp){
         //base case 
         if(i == a.length())return 0;
         if(j == b.length())return 0;// jab donoo end of the string aa gye tab rukna hai

 //step 3: check if answer already exists
 if(dp[i][j]!=-1){
     return dp[i][j];
 }


//step 2: answwre mei dp array daalo 
         //if char match 
         int ans =0;
         if(a[i] == b[j]){
             dp[i][j] = 1 + solveUsingMem(a,b,i+1,j+1,dp);
             // match hu toh curr char ko toh include karenge phir baaki recursion kaerga 
         }
         else{
             dp[i][j] =  0 + max(solveUsingMem(a,b,i,j+1,dp) , solveUsingMem(a,b,i+1,j,dp));
         }
         return dp[i][j];
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        int i=0;
        int j=0;
        // int ans = solveUsingRec(text1 , text2 , i, j);
        // return ans;

       // MEMOIZATION PROBLEM 
       //step1 : creata a dp array 
       vector<vector<int>>dp(text1.length(),vector<int>(text2.length() , -1));
        int ans = solveUsingMem(text1 , text2,i,j , dp);
        return ans;
        
    }
};