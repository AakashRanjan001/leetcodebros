
class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0;
        int n = nums.size();
        if (n <= 1) return 0; // If array size is 0 or 1, no jumps needed
        
        int farthest = 0;
        int l = 0;
        int r = 0;
        
        while(r < n - 1) {
            int next_farthest = farthest;
            for(int i = l; i <= r; i++) {
                next_farthest = max(next_farthest, i + nums[i]);
            }
            jumps++;
            l = r + 1;
            r = next_farthest;
            if (l >= n) break; // Prevents unnecessary iterations if already reached the end
        }
        
        return jumps;
    }
};