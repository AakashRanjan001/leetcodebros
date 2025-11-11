class Solution {
public:
    void convertstrsToNumStrs(vector<string>& strs,vector<pair<int,int>>&NumStrs){
           
           for(auto str:strs){
              int zeroes =0,ones = 0;
              for(auto ch:str){
                  if(ch == '0')zeroes++;
                  else ones++;
              }
              NumStrs.push_back(make_pair(zeroes,ones));
           }
    }

    // now we will use Include/Exclude principle
    int solveUsingRec( vector<pair<int,int>>&NumStrs,int i,int m, int n){
          //base case 
          if(i == NumStrs.size())return 0;

          int zeroes = NumStrs[i].first;
          int ones = NumStrs[i].second;
          int include =0,exclude =0;
       //include/exclude pattern 
         if(m - zeroes>=0 && n - ones>=0){ // YAHA DHYAN DENA !!!!
             include = 1 + solveUsingRec(NumStrs,i+1,m-zeroes,n-ones);
         }
         exclude = 0 + solveUsingRec(NumStrs,i+1,m,n);
         int ans = max(include,exclude);
         return ans;

    }
    int solveUsingMem( vector<pair<int,int>>&NumStrs,int i,int m, int n,  vector<vector<vector<int>>> &dp){
          if(i == NumStrs.size())return 0;

          if(dp[i][m][n]!=-1){
             return dp[i][m][n];
          }

          int zeroes = NumStrs[i].first;
          int ones = NumStrs[i].second;
          int include =0,exclude =0;
       //include/exclude pattern
         if(m - zeroes>=0 && n - ones>=0){
             include = 1 + solveUsingMem(NumStrs,i+1,m-zeroes,n-ones,dp);
         }
         exclude = 0 + solveUsingMem(NumStrs,i+1,m,n,dp);
        
         return dp[i][m][n];
    }
    int solveUsingTab(vector<pair<int,int>>&NumStrs, int m, int n){
        //step 1: create a Dp array 
        vector<vector<vector<int>>>dp(NumStrs.size()+1,vector<vector<int>>(m+1 ,vector<int>(n+1,0)));
        //step 2: base case dekho but all are 0 hence not required 

        //step 3: iterative approach 3 for loops
        for(int i=NumStrs.size()-1;i>=0;i--){
            for(int j =0;j<=m;j++){
                for(int k=0;k<=n;k++){
               

                 int zeroes = NumStrs[i].first;
                 int ones = NumStrs[i].second;
                 int include =0,exclude =0;
                  //include/exclude pattern
                 if(j - zeroes>=0 && k - ones>=0){
                     include = 1 + dp[i+1][j-zeroes][k-ones];
                  }
                   exclude = 0 + dp[i+1][j][k];
                   dp[i][j][k] = max(include,exclude);
                }
            }            
        }    
         return dp[0][m][n];
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        // we store the no.of zeroes and ones in one str
        vector<pair<int,int>>NumStrs;//{No.of zeroes, No.of Ones}
        convertstrsToNumStrs(strs, NumStrs);

        // int ans = solveUsingRec(NumStrs,0,m,n);
        // return ans;
       
       // all the three are varying that are 0,m,n ---> index,no.of zeroes,no.of ones 
       // we have to use 3D DP
       //step 1: create a 3D Dp  'i' varies from 0 -->NumStrs.size() --> size +1
       // m ---> varies from m--->0 => m+1 
        //  vector<vector<vector<int>>>dp(NumStrs.size()+1,vector<vector<int>>(m+1 ,vector<int>(n+1,-1)));
        // int ans = solveUsingMem(NumStrs,0,m,n,dp);
        // return ans;


        //tabulatiom 
        int ans = solveUsingTab(NumStrs,m,n);
        return ans;
    }
};