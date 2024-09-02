
class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        // Calculate the total chalk required in one round
        long long totalUsed = accumulate(chalk.begin(), chalk.end(), 0LL);  // Use long long to avoid overflow
        
        // Find the remaining chalk after full rounds
        k %= totalUsed;
        
        // Iterate through the chalk array to find the index
        for(int i = 0; i < chalk.size(); i++) {
            if(k < chalk[i]) return i;
            k -= chalk[i];
        }
        
        return -1; // This line should never be reached
    }
};