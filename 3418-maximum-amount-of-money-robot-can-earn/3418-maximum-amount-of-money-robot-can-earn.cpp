

//        //  int n = coins.size();
//        //  int m = coins[0].size();   // I THOUGHT THIS I WAS WRONG IT WAS A DP PROBLEM
//        //  int money =0;
//        //  bool moveright = false;
//        //  bool movedown  = false;
        
//        //  for(int i=0;i<n;i++){
//        //    for(int j=0;j<m;j++){
//        //        if(coins[i][j]>=0){
//        //            money+=coins[i][j];
//        //            if(coins[i][j+1]>=coins[i+1][j]){
//        //                moveright = true;
//        //                money+=coins[i][j+1];
                      
//        //            }
//        //            else{
//        //                 movedown = true;
//        //                money+=coins[i+1][j];
//        //            }
                  
//        //        }
//        //        else{
//        //            // agar beech mei kabhi negative aaye yab
//        //            if(coins[i][j]<0){
//        //                if(coins[i][j+1]<=coins[i+1][j]){
//        //                moveright = true;
//        //                money+=0;
                      
//        //            }
//        //            else{
//        //                 movedown = true;
//        //                money+=0;
//        //              }
//        //            }
                  
//        //        }
//        //    }
            
//        // }
//        //  return money;

// class Solution {
// public:
//     int n,m;
//     int solve(vector<vector<int>>& coins,int row,int col,int neu){
     
//         //base case 
//         if(row == n-1 && col == m-1){
//             if(coins[row][col]<0 && neu>0)return 0;
//            else  return coins[row][col];
//         }
//         if(row>=n || col>=m)return INT_MIN; // ye mai bhul gya tha 

//          int movedown =INT_MIN,moveright = INT_MIN;
//          int MD = INT_MIN,MR = INT_MIN;
//         //2 cases when coins[i][j]<0 && neu>0
//                      // coins[i][j]>0 
//            if(coins[row][col]>=0){
//                movedown = coins[row][col] + solve(coins,row+1,col,neu);
//                moveright = coins[row][col] + solve(coins,row,col+1,neu);
//           } 
//           if(coins[row][col] < 0 && neu > 0){
//               MD = 0 + solve(coins,row+1,col,neu-1);
//               MR = 0 + solve(coins,row,col+1,neu-1);
//           }        

//         return max(max(movedown,moveright),max(MD,MR)); 

//     }
//     int maximumAmount(vector<vector<int>>& coins) {
//            int n = coins.size();
//         int m = coins[0].size();
//         int ans = solve(coins,0,0,2);
//         return ans;
//     }
// };

class Solution {
public:
    // int n, m;

    // int solve(vector<vector<int>>& coins, int row, int col, int neu) {
    //     if (row == n - 1 && col == m - 1) {
    //         if (coins[row][col] < 0 && neu > 0) return 0; // Neutralize negative coin
    //         return coins[row][col];
    //     }

    //     // Out of bounds
    //     if (row >= n || col >= m) return INT_MIN;

    //     int moveDown = INT_MIN, moveRight = INT_MIN;
    //     int moveDownNeu = INT_MIN, moveRightNeu = INT_MIN;

    
    //     if (coins[row][col] >= 0) {
    //         moveDown = coins[row][col] + solve(coins, row + 1, col, neu);
    //         moveRight = coins[row][col] + solve(coins, row, col + 1, neu);
    //     }

    //     // Case 2: Negative coins at the current cell and `neu` > 0
    //     if (coins[row][col] < 0 && neu > 0) {
    //         moveDownNeu = solve(coins, row + 1, col, neu - 1);
    //         moveRightNeu = solve(coins, row, col + 1, neu - 1);
    //     }

    //     // Return the maximum of all possible moves
    //     int ans1 = max(moveDown,moveRight);
    //     int ans2 = max(moveDownNeu,moveRightNeu);
    //     return max(ans1,ans2);
    // }
     int n ,m ;

    int solve(vector<vector<int>> &coins, int row,int col,int ab,vector<vector<vector<int>>>&dp){
        if(row == n-1  && col == m-1){
            if( coins[row][col] < 0 && ab > 0)return 0;
            else return coins[row][col];
        }
        if(row >= n || col >= m)return -1e8;

        if(dp[row][col][ab] != INT_MIN)return dp[row][col][ab];
        int a = -1e8,b = -1e8;

        if(ab > 0 && coins[row][col] < 0){
            a = solve(coins,row+1,col,ab-1,dp);
            b = solve(coins,row,col+1,ab-1,dp);
        }

        int c = coins[row][col] + solve(coins,row+1,col,ab,dp);
        int d = coins[row][col] + solve(coins,row,col+1,ab,dp);

        return dp[row][col][ab] =  max(max(a,b),max(c,d));
    }

    int maximumAmount(vector<vector<int>>& coins) {
        n = coins.size();
        m = coins[0].size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(3,INT_MIN)));
        return solve(coins,0,0,2,dp);
    }
};