class Solution {
public:
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
    int longestPalindromeSubseq(string &s) {
       string s2 = s;
        reverse(s2.begin(),s2.end());
        int n1 = s.size();
        int n2 = s2.size(); 

        vector<vector<int>>dp(n1+1,vector<int>(n2+1,-1));
        int ans = solveUsingMem(s,s2,n1-1,n2-1,dp);
        return ans;
    }
    int minInsertions(string s) {
        int LPS_len = longestPalindromeSubseq(s);
        int insertionToDo = s.size() - LPS_len;
        return insertionToDo;
    }
};