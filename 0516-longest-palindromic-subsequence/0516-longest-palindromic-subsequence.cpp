class Solution {
public:
    int solveUsingRec(string &s ,string&s2, int index1 , int index2){
        //base case 
        if(index1<0 || index2<0){
            return 0;
        }
        int ans =0;
        if(s[index1] == s2[index2]){
             ans =  1 + solveUsingRec(s,s2,index1-1,index2-1);
        }
        else{
            ans = 0 + max(solveUsingRec(s,s2,index1-1,index2),solveUsingRec(s,s2,index1,index2-1));
        } 
        return ans;   
    }

    int solveUsingMem(string &s ,string&s2, int index1 , int index2, vector<vector<int>> &dp){
          if(index1<0 || index2<0){
            return 0;
        }
        if(dp[index1][index2] !=-1){
             return dp[index1][index2];
        }
        int ans =0;
        if(s[index1] == s2[index2]){
             ans =  1 + solveUsingMem(s,s2,index1-1,index2-1,dp);
        }
        else{
            ans = 0 + max(solveUsingMem(s,s2,index1-1,index2,dp),solveUsingMem(s,s2,index1,index2-1,dp));
        } 
       return dp[index1][index2] = ans;
    }
    int solveUsingTab(string s , string s2){
     int n1 = s.size();
    int n2 = s2.size();
    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));  // Initialize dp table

    for (int index1 = 1; index1 <= n1; index1++) {
        for (int index2 = 1; index2 <= n2; index2++) {
            if (s[index1 - 1] == s2[index2 - 1]) {  // Compare characters from both strings
                dp[index1][index2] = 1 + dp[index1 - 1][index2 - 1];
            } else {
                dp[index1][index2] = max(dp[index1 - 1][index2], dp[index1][index2 - 1]);
            }
        }
    }

    return dp[n1][n2];
    }
    int longestPalindromeSubseq(string s) {
        string s2 = s;
        reverse(s2.begin(),s2.end());
        int n1 = s.size();
        int n2 = s2.size(); 
        // int ans = solveUsingRec(s,s2,n1-1,n2-1);
        // return ans;
        
        // vector<vector<int>>dp(n1+1,vector<int>(n2+1,-1));
        // int ans = solveUsingMem(s,s2,n1-1,n2-1,dp);
        // return ans;

        int ans = solveUsingTab(s,s2);
        return ans;
    }

};