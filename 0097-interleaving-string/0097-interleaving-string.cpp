class Solution {
public:
    bool solveUsingRec(string &s1,string&s2 , string &s3,int i,int j,int k){
         //base case
         if(i==s1.size() && j == s2.size() && k == s3.size())return true;

          bool flag = false;
         if(i<s1.size() && s1[i] == s3[k]){
            flag=flag || solveUsingRec(s1,s2,s3,i+1,j,k+1);
            // we have done OR becuase flag ka value change tab hota hai jab apon return karte hai 
             // agar s1 == s3 hi ho gya matlab s2 jaane ki jaroorat hi nhi hai falg = false || true ho jayega and hence always true bann jayega 
         }
         if( j< s2.size() && s2[j] == s3[k]){
            flag=flag || solveUsingRec(s1,s2,s3,i,j+1,k+1);
         }
         return flag;
    }
bool solveUsingMem(string &s1,string&s2 , string &s3,int i,int j,int k,   vector<vector<vector<int>>> &dp){
     if(i==s1.size() && j == s2.size() && k == s3.size())return true;

      if(dp[i][j][k]!=-1)return dp[i][j][k];

          bool flag = false;
         if(i<s1.size() && s1[i] == s3[k]){
            flag=flag || solveUsingMem(s1,s2,s3,i+1,j,k+1,dp);
            // we have done OR becuase flag ka value change tab hota hai jab apon return karte hai 
             // agar s1 == s3 hi ho gya matlab s2 jaane ki jaroorat hi nhi hai falg = false || true ho jayega and hence always true bann jayega 
         }
         if( j< s2.size() && s2[j] == s3[k]){
            flag=flag || solveUsingMem(s1,s2,s3,i,j+1,k+1,dp);
         }
         return dp[i][j][k] = flag;
}
   bool solveUsingTab(string &s1,string&s2 , string &s3){
    vector<vector<vector<int>>> dp(s1.size() + 1, vector<vector<int>>(s2.size() + 1, vector<int>(s3.size() + 1, 0)));
        
        dp[s1.size()][s2.size()][s3.size()] = 1; // agar khaali hai tab ke liye kaam ka hai 

       for(int i = s1.size();i>=0;i--){
          for(int j=s2.size();j>=0;j--){
             for(int k=s3.size();k>=0;k--){
                if(i==s1.size() && j == s2.size() && k == s3.size())continue;
                     bool flag = false;
                    if(i<s1.size() && s1[i] == s3[k]){
                     flag=flag || dp[i+1][j][k+1];
                      // we have done OR becuase flag ka value change tab hota hai jab apon return karte hai 
                        // agar s1 == s3 hi ho gya matlab s2 jaane ki jaroorat hi nhi hai falg = false || true ho jayega and hence always true bann jayega 
                    }
               if( j< s2.size() && s2[j] == s3[k]){
                   flag=flag || dp[i][j+1][k+1];
                }
              dp[i][j][k] = flag;

             }
          }
       }
       return dp[0][0][0];

   }
     
    bool isInterleave(string s1, string s2, string s3) {
        // bool ans = solveUsingRec(s1,s2,s3,0,0,0);
        // return ans;

      
    //   vector<vector<vector<int>>> dp(s1.size() + 1, vector<vector<int>>(s2.size() + 1, vector<int>(s3.size() + 1, -1)));

    //     bool ans = solveUsingMem(s1,s2,s3,0,0,0,dp);
    //     return ans;

    bool ans = solveUsingTab(s1,s2,s3);
    return ans;
    }

};