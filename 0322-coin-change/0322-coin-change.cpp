class Solution {
public:
    // int solveUsingRec(vector<int>& coins, int amount){
    //     // base case 
    //     if(amount == 0){
    //          return 0;
    //     }
    //     if(amount<0){
    //          return INT_MAX; //means ye genuinuley hame batata hai ki hamara ye answr nhi hai 
    //                          // INT_MAX ke alawa bhi ek value use kar sakta hai for this 
    //     }
    //     int mini = INT_MAX;
    //     //ek mini amount taaki mini coins ka pata chal sake
    //     for(int i=0;i<coins.size();i++){
    //         int ans = solveUsingRec(coins,amount-coins[i]);
    //          if(ans != INT_MAX){
    //              // YAHA MAI GALTI KARTA HU PAKKA !!!!!!!!
    //              mini = min(mini,1+ans); // 1 isiliye add kiye kyunki function call kar rhe woh amount -coins[i] ke liye kar rhe , jo shuraut ka coin tha jiska
    //                 // value amount = 11 tha uska apon consider hi nhi kiye , thats why ans mei nhi aa rha tah 
    //          }
    //     }
    //     return mini;      
    // }

    // int solvemem(vector<int>& coins , int amount , vector<int>& dp ){
    //          // base case 
    //     if(amount == 0){
    //          return 0;
    //     }
    //     if(amount<0){
    //          return INT_MAX; //means ye genuinuley hame batata hai ki hamara ye answr nhi hai 
    //                          // INT_MAX ke alawa bhi ek value use kar sakta hai for this 
    //     }
    //  //chcek whwtehr aanswer already exist 
    //   if(dp[amount]!=-1){
    //      return dp[amount];
    //   }

    //     int mini = INT_MAX;
        
    //     for(int i=0;i<coins.size();i++){
    //         int ans = solvemem(coins,amount-coins[i],dp);
    //          if(ans != INT_MAX){
    //              // YAHA MAI GALTI KARTA HU PAKKA !!!!!!!!
    //              mini = min(mini,1+ans); // 1 isiliye add kiye kyunki function call kar rhe woh amount -coins[i] ke liye kar rhe , jo shuraut ka coin tha jiska
    //                 // value amount = 11 tha uska apon consider hi nhi kiye , thats why ans mei nhi aa rha tah 
    //          }
    //     }
    //     //spet2: jaha answer likha hai waha par
    //     dp[amount] = mini;
    //     return dp[amount];
    // }

    int bottomup(vector<int>& coins , int amount){
      //step1 : Create a array 
      vector<int>dp(amount+1 , INT_MAX);

      //step2: 
      //base case ko dp ke form mei likho
      dp[0] = 0;// yaha galti karta hu
       // 'i' 1 se start kiya hai 0 se start nhi kiya maine 
       // yaha dimaag lagta hai
      for(int i=1;i<=amount;i++){
         // har ek amount ke liye mai saari calls maarta 
         for(int j=0;j<coins.size();j++){

            if(i-coins[j]>=0 && dp[i-coins[j]]!=INT_MAX ){
             int ans1 = dp[i-coins[j]];// jo bhi recursive calls hai usko dp se replace kar dunga 
              dp[i] = min(dp[i], 1 + ans1);
            }
        
         }

      }
      return dp[amount];

    }
    int coinChange(vector<int>& coins, int amount) {
        //  int ans = solveUsingRec(coins,amount);
        //  if(ans == INT_MAX)return -1;
        //  return ans;
        
        //step 1: Create a DP arrya
        // vector<int>dp(amount+1 , -1);
        // int ans = solvemem(coins,amount,dp);
        // if(ans == INT_MAX)return -1;
        // else
        // return ans;

        int ans = bottomup(coins,amount);
        if(ans == INT_MAX)return -1;
        return ans;
    }
};


