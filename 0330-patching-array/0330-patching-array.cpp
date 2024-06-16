class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
         int patch = 0;
       long long int sum = 0;  
        int i = 0;
        
       
       while (sum < n) {
            if (i < nums.size() && nums[i] <= sum + 1) {
               
                sum += nums[i];
                i++;
            } else {
               
                sum += sum + 1;
                patch++;
            }
        }
        
        return patch;
    }
};
