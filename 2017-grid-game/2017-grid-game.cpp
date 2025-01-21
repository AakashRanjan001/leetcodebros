// class Solution {
// public:
//     long long gridGame(vector<vector<int>>& grid) {
        
//         long long UpperRowSum = 0;
//         long long MaxSecondRobotSum =0;
//         long long lowerRowSum =0;

//         for(int i=0;i<grid[0].size();i++){
//              UpperRowSum+=grid[0][i];
//         }
//         for(int col =0;col<grid[0].size();col++){ 
//             UpperRowSum-=grid[0][col];
//             MaxSecondRobotSum = min(MaxSecondRobotSum,max(UpperRowSum,lowerRowSum));
//             lowerRowSum+=grid[1][col];
//         }
//         return MaxSecondRobotSum;
//     }
// };
class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long UpperRowSum = 0, lowerRowSum = 0;
        long long MaxSecondRobotSum = LLONG_MAX; // Initialize to a large value
        
        int n = grid[0].size();
        
        for(int i = 0; i < n; i++) {
            UpperRowSum += grid[0][i]; // Compute total sum of the first row
        }

        for(int col = 0; col < n; col++) { 
            UpperRowSum -= grid[0][col]; // First robot moves right, leaving cells behind
            MaxSecondRobotSum = min(MaxSecondRobotSum, max(UpperRowSum, lowerRowSum)); // Minimize worst case
            lowerRowSum += grid[1][col]; // Second robot accumulates sum in bottom row
        }

        return MaxSecondRobotSum;
    }
};


