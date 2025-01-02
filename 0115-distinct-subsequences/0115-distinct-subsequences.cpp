class Solution {
public:
    int solveUsingRec(string &s, string &t , int i , int j){
         //base case 
         if(j == t.size())return 1; //agar j pahuch gya end of teh string mei matlab dono char match ho gye the 
         if(i == s.size())return 0;//agar i pehle pahuch gya end tak aur j nhi pahucha hai hence we return 0
         int ans =0;
         if(s[i] == t[j]){
             ans+=solveUsingRec(s,t,i+1,j+1);
         }
          ans+=solveUsingRec(s,t,i+1,j);
          return ans;
    }
    int solveUsingMem(string &s, string &t , int i , int j, vector<vector<int>> &dp){
        if(j == t.size())return 1; //agar j pahuch gya end of teh string mei matlab dono char match ho gye the 
         if(i == s.size())return 0;//agar i pehle pahuch gya end tak aur j nhi pahucha hai hence we return 0

         if(dp[i][j]!=-1){
             return dp[i][j];
         }
         int ans =0;
         if(s[i] == t[j]){
             ans+=solveUsingMem(s,t,i+1,j+1,dp);
         }
          ans+=solveUsingMem(s,t,i+1,j,dp);
          return dp[i][j] =  ans;

    }
    int numDistinct(string s, string t) {
        // int ans = solveUsingRec(s,t,0,0);
        // return ans;

        //here both i and j are changing hence we use 2D DP
        //step 1: creation of a DP array
        vector<vector<int>>dp(s.size()+1 ,vector<int>(t.size()+1,-1));
        int ans = solveUsingMem(s,t,0,0,dp);
        return ans;
    }
};