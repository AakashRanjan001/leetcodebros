class Solution {
public:
    bool check(vector<string>& wordDict,string &s){
        for(auto i:wordDict){
             if(s == i){
                 return true;
             }
        }
        return false;
         
    }
    bool solveUsingRec(string &s, vector<string>& wordDict,int start ){
         //base case 
         if( start == s.size())return true;
         //1 case solve 
         string word = "";
         bool flag = false;// current word abhi wordDict mei nhi bai filhaal loop ke baad pata chaelga 
         for(int i=start;i<s.size();i++){
             word+=s[i];//current word ko check kar rhe ki woh wordDict mei present hai ki nhi 
             if(check(wordDict , word) == true){
                 //agar true huamens ek valid word hai jo wordDict mei prsesent hai      toh baaki recursion solve karke layega 
                 flag = flag || solveUsingRec(s,wordDict,i+1);// handling an important case 
             }
         }
         return flag;
    }

    bool solveUsingMem(string &s, vector<string>& wordDict, int start ,vector<int> &dp ){
         if( start == s.size())return true;

         if(dp[start]!=-1){
             return dp[start];
         }
         //1 case solve 
         string word = "";
         bool flag = false;// current word abhi wordDict mei nhi bai filhaal loop ke baad pata chaelga 
         for(int i=start;i<s.size();i++){
             word+=s[i];//current word ko check kar rhe ki woh wordDict mei present hai ki nhi 
             if(check(wordDict , word) == true){
                 //agar true huamens ek valid word hai jo wordDict mei prsesent hai      toh baaki recursion solve karke layega 
                 flag = flag || solveUsingMem(s,wordDict,i+1,dp);// handling an important case 
             }  
         }
          dp[start] = flag;
         return dp[start];
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        // return solveUsingRec(s,wordDict,0);


        //memoization 
        //only one variable is changing and hece we will use 1 D dp
        vector<int>dp(s.size() + 1,-1);
        return solveUsingMem(s,wordDict,0,dp);
    }
};