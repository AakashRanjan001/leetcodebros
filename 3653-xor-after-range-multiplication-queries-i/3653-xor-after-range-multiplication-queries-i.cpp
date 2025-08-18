class Solution {
public:
    #define MOD 1000000007
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
         for(auto i:queries){
             int idx = i[0];
             int r = i[1];
             int v = i[3];
             int k = i[2];
          

             while(idx<=r){
                 nums[idx] = (1LL *nums[idx] * v) % MOD;
                    idx+=k;
             }
          

         }
         int XOR = 0;
         for(auto i:nums){
             XOR^=i;
         }
         return XOR;
    }
};